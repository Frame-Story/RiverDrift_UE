// Generated code -- CC0 -- No Rights Reserved -- http://www.redblobgames.com/grids/hexagons/

#include "HexLibrary.h"
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
using std::abs;
using std::max;
using std::vector;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif





// Forward declarations


FHex UHexLibrary::hex_add(FHex a, FHex b)
{
    return FHex(a.q + b.q, a.r + b.r, a.s + b.s);
}


FHex UHexLibrary::hex_subtract(FHex a, FHex b)
{
    return FHex(a.q - b.q, a.r - b.r, a.s - b.s);
}


FHex UHexLibrary::hex_scale(FHex a, int k)
{
    return FHex(a.q * k, a.r * k, a.s * k);
}


FHex UHexLibrary::hex_rotate_left(FHex a)
{
    return FHex(-a.s, -a.q, -a.r);
}


FHex UHexLibrary::hex_rotate_right(FHex a)
{
    return FHex(-a.r, -a.s, -a.q);
}


static const TArray<FHex> hex_directions = { FHex(1, 0, -1), FHex(1, -1, 0), FHex(0, -1, 1), FHex(-1, 0, 1), FHex(-1, 1, 0), FHex(0, 1, -1) };
FHex UHexLibrary::hex_direction(int direction)
{
    return hex_directions[direction];
}


FHex UHexLibrary::hex_neighbor(FHex hex, int direction)
{
    return hex_add(hex, hex_direction(direction));
}


static const TArray<FHex> hex_diagonals = { FHex(2, -1, -1), FHex(1, -2, 1), FHex(-1, -1, 2), FHex(-2, 1, 1), FHex(-1, 2, -1), FHex(1, 1, -2) };

FHex UHexLibrary::hex_diagonal_neighbor(FHex hex, int direction)
{
    return hex_add(hex, hex_diagonals[direction]);
}


int UHexLibrary::hex_length(FHex hex)
{
    return int((abs(hex.q) + abs(hex.r) + abs(hex.s)) / 2);
}


int UHexLibrary::hex_distance(FHex a, FHex b)
{
    return hex_length(hex_subtract(a, b));
}


//turns fractional hex coord into the nearest(?) integer hex coord
FHex UHexLibrary::hex_round(FFractionalHex h)
{
    int qi = int(round(h.q));
    int ri = int(round(h.r));
    int si = int(round(h.s));
    double q_diff = abs(qi - h.q);
    double r_diff = abs(ri - h.r);
    double s_diff = abs(si - h.s);
    if (q_diff > r_diff && q_diff > s_diff)
    {
        qi = -ri - si;
    }
    else
        if (r_diff > s_diff)
        {
            ri = -qi - si;
        }
        else
        {
            si = -qi - ri;
        }
    return FHex(qi, ri, si);
}


FFractionalHex UHexLibrary::hex_lerp(FFractionalHex a, FFractionalHex b, double t)
{
    return FFractionalHex(a.q * (1.0 - t) + b.q * t, a.r * (1.0 - t) + b.r * t, a.s * (1.0 - t) + b.s * t);
}


TArray<FHex> UHexLibrary::hex_linedraw(FHex a, FHex b)
{
    int N = hex_distance(a, b);
    FFractionalHex a_nudge = FFractionalHex(a.q + 1e-06, a.r + 1e-06, a.s - 2e-06);
    FFractionalHex b_nudge = FFractionalHex(b.q + 1e-06, b.r + 1e-06, b.s - 2e-06);
    TArray<FHex> results = {};
    double step = 1.0 / max(N, 1);
    for (int i = 0; i <= N; i++)
    {
        results.Push(hex_round(hex_lerp(a_nudge, b_nudge, step * i)));
    }
    return results;
}


FOffsetCoord UHexLibrary::offset_from_cube(FHex h, int offset)
{
    int col = h.q;
    int row = h.r + int((h.q + offset * (h.q & 1)) / 2);
    if (offset != EVEN && offset != ODD)
    {
        throw "offset must be EVEN (+1) or ODD (-1)";
    }
    return FOffsetCoord(col, row);
}


FHex UHexLibrary::offset_to_cube(int offset, FOffsetCoord h)
{
    int q = h.col;
    int r = h.row - int((h.col + offset * (h.col & 1)) / 2);
    int s = -q - r;
    if (offset != EVEN && offset != ODD)
    {
        throw "offset must be EVEN (+1) or ODD (-1)";
    }
    return FHex(q, r, s);
}

//
//FOffsetCoord UHexLibrary::roffset_from_cube(int offset, FHex h)
//{
//    int col = h.q + int((h.r + offset * (h.r & 1)) / 2);
//    int row = h.r;
//    if (offset != EVEN && offset != ODD)
//    {
//        throw "offset must be EVEN (+1) or ODD (-1)";
//    }
//    return FOffsetCoord(col, row);
//}

//
//FHex UHexLibrary::roffset_to_cube(int offset, FOffsetCoord h)
//{
//    int q = h.col - int((h.row + offset * (h.row & 1)) / 2);
//    int r = h.row;
//    int s = -q - r;
//    if (offset != EVEN && offset != ODD)
//    {
//        throw "offset must be EVEN (+1) or ODD (-1)";
//    }
//    return FHex(q, r, s);
//}



FDoubledCoord UHexLibrary::doubled_from_cube(FHex h)
{
    int col = h.q;
    int row = 2 * h.r + h.q;
    return FDoubledCoord(col, row);
}


FHex UHexLibrary::doubled_to_cube(FDoubledCoord h)
{
    int q = h.col;
    int r = int((h.row - h.col) / 2);
    int s = -q - r;
    return FHex(q, r, s);
}

//
//FDoubledCoord UHexLibrary::rdoubled_from_cube(FHex h)
//{
//    int col = 2 * h.q + h.r;
//    int row = h.r;
//    return FDoubledCoord(col, row);
//}

//
//FHex UHexLibrary::rdoubled_to_cube(FDoubledCoord h)
//{
//    int q = int((h.col - h.row) / 2);
//    int r = h.row;
//    int s = -q - r;
//    return FHex(q, r, s);
//}




const FOrientation layout_pointy = FOrientation(sqrt(3.0), sqrt(3.0) / 2.0, 0.0, 3.0 / 2.0, sqrt(3.0) / 3.0, -1.0 / 3.0, 0.0, 2.0 / 3.0, 0.5);
const FOrientation layout_flat = FOrientation(3.0 / 2.0, 0.0, sqrt(3.0) / 2.0, sqrt(3.0), 2.0 / 3.0, 0.0, -1.0 / 3.0, sqrt(3.0) / 3.0, 0.0);
FPoint UHexLibrary::hex_to_pixel(FLayout layout, FHex h)
{
    FOrientation M = layout.orientation;
    FPoint size = layout.size;
    FPoint origin = layout.origin;
    double x = (M.f0 * h.q + M.f1 * h.r) * size.x;
    double y = (M.f2 * h.q + M.f3 * h.r) * size.y;
    return FPoint(x + origin.x, y + origin.y);
}


FFractionalHex UHexLibrary::pixel_to_hex(FLayout layout, FPoint p)
{
    FOrientation M = layout.orientation;
    FPoint size = layout.size;
    FPoint origin = layout.origin;
    FPoint pt = FPoint((p.x - origin.x) / size.x, (p.y - origin.y) / size.y);
    double q = M.b0 * pt.x + M.b1 * pt.y;
    double r = M.b2 * pt.x + M.b3 * pt.y;
    return FFractionalHex(q, r, -q - r);
}


FPoint UHexLibrary::hex_corner_offset(FLayout layout, int corner)
{
    FOrientation M = layout.orientation;
    FPoint size = layout.size;
    double angle = 2.0 * M_PI * (M.start_angle - corner) / 6.0;
    return FPoint(size.x * cos(angle), size.y * sin(angle));
}


TArray<FPoint> UHexLibrary::polygon_corners(FLayout layout, FHex h)
{
    TArray<FPoint> corners = {};
    FPoint center = hex_to_pixel(layout, h);
    for (int i = 0; i < 6; i++)
    {
        FPoint offset = hex_corner_offset(layout, i);
        corners.Push(FPoint(center.x + offset.x, center.y + offset.y));
    }
    return corners;
}




//// Tests
//
//#include <iostream>
//
//void complain(const char* name)
//{
//    std::cout << "FAIL " << name << std::endl;
//}
//
//
//void equal_hex(const char* name, FHex a, FHex b)
//{
//    if (!(a.q == b.q && a.s == b.s && a.r == b.r))
//    {
//        complain(name);
//    }
//}
//
//
//void equal_offsetcoord(const char* name, FOffsetCoord a, FOffsetCoord b)
//{
//    if (!(a.col == b.col && a.row == b.row))
//    {
//        complain(name);
//    }
//}
//
//
//void equal_doubledcoord(const char* name, FDoubledCoord a, FDoubledCoord b)
//{
//    if (!(a.col == b.col && a.row == b.row))
//    {
//        complain(name);
//    }
//}
//
//
//void equal_int(const char* name, int a, int b)
//{
//    if (!(a == b))
//    {
//        complain(name);
//    }
//}
//
//
//void equal_hex_array(const char* name, vector<FHex> a, vector<FHex> b)
//{
//    equal_int(name, a.size(), b.size());
//    for (int i = 0; i < a.size(); i++)
//    {
//        equal_hex(name, a[i], b[i]);
//    }
//}
//
//
//void test_hex_arithmetic()
//{
//    equal_hex("hex_add", FHex(4, -10, 6), hex_add(FHex(1, -3, 2), FHex(3, -7, 4)));
//    equal_hex("hex_subtract", FHex(-2, 4, -2), hex_subtract(FHex(1, -3, 2), FHex(3, -7, 4)));
//}
//
//
//void test_hex_direction()
//{
//    equal_hex("hex_direction", FHex(0, -1, 1), hex_direction(2));
//}
//
//
//void test_hex_neighbor()
//{
//    equal_hex("hex_neighbor", FHex(1, -3, 2), hex_neighbor(FHex(1, -2, 1), 2));
//}
//
//
//void test_hex_diagonal()
//{
//    equal_hex("hex_diagonal", FHex(-1, -1, 2), hex_diagonal_neighbor(FHex(1, -2, 1), 3));
//}
//
//
//void test_hex_distance()
//{
//    equal_int("hex_distance", 7, hex_distance(FHex(3, -7, 4), FHex(0, 0, 0)));
//}
//
//
//void test_hex_rotate_right()
//{
//    equal_hex("hex_rotate_right", hex_rotate_right(FHex(1, -3, 2)), FHex(3, -2, -1));
//}
//
//
//void test_hex_rotate_left()
//{
//    equal_hex("hex_rotate_left", hex_rotate_left(FHex(1, -3, 2)), FHex(-2, -1, 3));
//}
//
//
//void test_hex_round()
//{
//    FFractionalHex a = FFractionalHex(0.0, 0.0, 0.0);
//    FractionalHex b = FractionalHex(1.0, -1.0, 0.0);
//    FractionalHex c = FractionalHex(0.0, -1.0, 1.0);
//    equal_hex("hex_round 1", FHex(5, -10, 5), hex_round(hex_lerp(FractionalHex(0.0, 0.0, 0.0), FractionalHex(10.0, -20.0, 10.0), 0.5)));
//    equal_hex("hex_round 2", hex_round(a), hex_round(hex_lerp(a, b, 0.499)));
//    equal_hex("hex_round 3", hex_round(b), hex_round(hex_lerp(a, b, 0.501)));
//    equal_hex("hex_round 4", hex_round(a), hex_round(FractionalHex(a.q * 0.4 + b.q * 0.3 + c.q * 0.3, a.r * 0.4 + b.r * 0.3 + c.r * 0.3, a.s * 0.4 + b.s * 0.3 + c.s * 0.3)));
//    equal_hex("hex_round 5", hex_round(c), hex_round(FractionalHex(a.q * 0.3 + b.q * 0.3 + c.q * 0.4, a.r * 0.3 + b.r * 0.3 + c.r * 0.4, a.s * 0.3 + b.s * 0.3 + c.s * 0.4)));
//}
//
//
//void test_hex_linedraw()
//{
//    equal_hex_array("hex_linedraw", { FHex(0, 0, 0), FHex(0, -1, 1), FHex(0, -2, 2), FHex(1, -3, 2), FHex(1, -4, 3), FHex(1, -5, 4) }, hex_linedraw(FHex(0, 0, 0), FHex(1, -5, 4)));
//}
//
//
//void test_layout()
//{
//    FHex h = FHex(3, 4, -7);
//    Layout flat = Layout(layout_flat, Point(10.0, 15.0), Point(35.0, 71.0));
//    equal_hex("layout", h, hex_round(pixel_to_hex(flat, hex_to_pixel(flat, h))));
//    Layout pointy = Layout(layout_pointy, Point(10.0, 15.0), Point(35.0, 71.0));
//    equal_hex("layout", h, hex_round(pixel_to_hex(pointy, hex_to_pixel(pointy, h))));
//}
//
//
//void test_offset_roundtrip()
//{
//    FHex a = FHex(3, 4, -7);
//    FOffsetCoord b = FOffsetCoord(1, -3);
//    equal_hex("conversion_roundtrip even-q", a, qoffset_to_cube(EVEN, qoffset_from_cube(EVEN, a)));
//    equal_offsetcoord("conversion_roundtrip even-q", b, qoffset_from_cube(EVEN, qoffset_to_cube(EVEN, b)));
//    equal_hex("conversion_roundtrip odd-q", a, qoffset_to_cube(ODD, qoffset_from_cube(ODD, a)));
//    equal_offsetcoord("conversion_roundtrip odd-q", b, qoffset_from_cube(ODD, qoffset_to_cube(ODD, b)));
//    equal_hex("conversion_roundtrip even-r", a, roffset_to_cube(EVEN, roffset_from_cube(EVEN, a)));
//    equal_offsetcoord("conversion_roundtrip even-r", b, roffset_from_cube(EVEN, roffset_to_cube(EVEN, b)));
//    equal_hex("conversion_roundtrip odd-r", a, roffset_to_cube(ODD, roffset_from_cube(ODD, a)));
//    equal_offsetcoord("conversion_roundtrip odd-r", b, roffset_from_cube(ODD, roffset_to_cube(ODD, b)));
//}
//
//
//void test_offset_from_cube()
//{
//    equal_offsetcoord("offset_from_cube even-q", FOffsetCoord(1, 3), qoffset_from_cube(EVEN, FHex(1, 2, -3)));
//    equal_offsetcoord("offset_from_cube odd-q", FOffsetCoord(1, 2), qoffset_from_cube(ODD, FHex(1, 2, -3)));
//}
//
//
//void test_offset_to_cube()
//{
//    equal_hex("offset_to_cube even-", FHex(1, 2, -3), qoffset_to_cube(EVEN, FOffsetCoord(1, 3)));
//    equal_hex("offset_to_cube odd-q", FHex(1, 2, -3), qoffset_to_cube(ODD, FOffsetCoord(1, 2)));
//}
//
//
//void test_doubled_roundtrip()
//{
//    FHex a = FHex(3, 4, -7);
//    FDoubledCoord b = FDoubledCoord(1, -3);
//    equal_hex("conversion_roundtrip doubled-q", a, qdoubled_to_cube(qdoubled_from_cube(a)));
//    equal_doubledcoord("conversion_roundtrip doubled-q", b, qdoubled_from_cube(qdoubled_to_cube(b)));
//    equal_hex("conversion_roundtrip doubled-r", a, rdoubled_to_cube(rdoubled_from_cube(a)));
//    equal_doubledcoord("conversion_roundtrip doubled-r", b, rdoubled_from_cube(rdoubled_to_cube(b)));
//}
//
//
//void test_doubled_from_cube()
//{
//    equal_doubledcoord("doubled_from_cube doubled-q", FDoubledCoord(1, 5), qdoubled_from_cube(FHex(1, 2, -3)));
//    equal_doubledcoord("doubled_from_cube doubled-r", FDoubledCoord(4, 2), rdoubled_from_cube(FHex(1, 2, -3)));
//}
//
//
//void test_doubled_to_cube()
//{
//    equal_hex("doubled_to_cube doubled-q", FHex(1, 2, -3), qdoubled_to_cube(FDoubledCoord(1, 5)));
//    equal_hex("doubled_to_cube doubled-r", FHex(1, 2, -3), rdoubled_to_cube(FDoubledCoord(4, 2)));
//}
//
//
//void test_all()
//{
//    test_hex_arithmetic();
//    test_hex_direction();
//    test_hex_neighbor();
//    test_hex_diagonal();
//    test_hex_distance();
//    test_hex_rotate_right();
//    test_hex_rotate_left();
//    test_hex_round();
//    test_hex_linedraw();
//    test_layout();
//    test_offset_roundtrip();
//    test_offset_from_cube();
//    test_offset_to_cube();
//    test_doubled_roundtrip();
//    test_doubled_from_cube();
//    test_doubled_to_cube();
//}
//
//
//
//
//
//int main() {
//    std::cout << "warning, the main func in HexLib is in fact getting called" << std::endl;
//    //test_all();
//}
//

