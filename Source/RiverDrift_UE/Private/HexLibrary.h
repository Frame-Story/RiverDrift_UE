// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexLibrary.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FHex
{
    GENERATED_BODY()

public:

    //again, might be able to be replaced with Unreal's vec3.
    //advantage of this approach is that the values are explicitly nameddo I
    //advantage of refactoring to vec3 would be the possibility of built in operations
    const int q;
    const int r;
    const int s;

    FHex(int q_, int r_, int s_) : q(q_), r(r_), s(s_) {
        if (q + r + s != 0) throw "q + r + s must be 0";
    }

    FHex() : q(0), r(0), s(0) {}

    //String ToString() {
    //    return (ToString(q) + " " + ToString(r) + " " + ToString(s));
    //}
};

USTRUCT(BlueprintType)
//interchangable with vector2, but just what was used in this lib
struct FPoint
{

    GENERATED_BODY()

    const double x;
    const double y;
    FPoint(double x_, double y_) : x(x_), y(y_) {}
};


USTRUCT(BlueprintType)
struct FFractionalHex
{
    GENERATED_BODY()
 
    const double q;
    const double r;
    const double s;
    FFractionalHex(double q_, double r_, double s_) : q(q_), r(r_), s(s_) {
        if (round(q + r + s) != 0) throw "q + r + s must be 0";
    }
};


USTRUCT(BlueprintType)
struct FOffsetCoord
{
    GENERATED_BODY()

public:
    const int col;
    const int row;
    FOffsetCoord(int col_, int row_) : col(col_), row(row_) {}
};


USTRUCT(BlueprintType)
struct FDoubledCoord
{
    GENERATED_BODY()

    const int col;
    const int row;
    FDoubledCoord(int col_, int row_) : col(col_), row(row_) {}
};


USTRUCT(BlueprintType)
struct FOrientation
{
    GENERATED_BODY()

    const double f0;
    const double f1;
    const double f2;
    const double f3;
    const double b0;
    const double b1;
    const double b2;
    const double b3;
    const double start_angle;
    FOrientation(double f0_, double f1_, double f2_, double f3_, double b0_, double b1_, double b2_, double b3_, double start_angle_) : f0(f0_), f1(f1_), f2(f2_), f3(f3_), b0(b0_), b1(b1_), b2(b2_), b3(b3_), start_angle(start_angle_) {}
};


USTRUCT(BlueprintType)
struct FLayout
{
    GENERATED_BODY()

    const FOrientation orientation;
    const FPoint size;
    const FPoint origin;
    FLayout(FOrientation orientation_, FPoint size_, FPoint origin_) : orientation(orientation_), size(size_), origin(origin_) {}
};



UCLASS()

class UHexLibrary : public UObject
{
    GENERATED_BODY()

public:
    static FHex hex_add(FHex a, FHex b);





    static FHex hex_subtract(FHex a, FHex b);


    static FHex hex_scale(FHex a, int k);

    static FHex hex_rotate_left(FHex a);


    static FHex hex_rotate_right(FHex a);

    static FHex hex_direction(int direction);

    static FHex hex_neighbor(FHex hex, int direction);

    //static TArray<FHex> hex_diagonals();
    static FHex hex_diagonal_neighbor(FHex hex, int direction);

    static int hex_length(FHex hex);

    static int hex_distance(FHex a, FHex b);

    //turns fractional hex coord into the nearest(?) integer hex coord
    static FHex hex_round(FFractionalHex h);

    static FFractionalHex hex_lerp(FFractionalHex a, FFractionalHex b, double t);

    static TArray<FHex> hex_linedraw(FHex a, FHex b);

    static const int EVEN = 1;
    static const int ODD = -1;



    static FOffsetCoord offset_from_cube(FHex h, int offset = EVEN);

    static FHex offset_to_cube(int offset, FOffsetCoord h);
    
    static  FDoubledCoord doubled_from_cube(FHex h);
    
    static  FHex doubled_to_cube(FDoubledCoord h);
    //r is point top

    //static FOffsetCoord roffset_from_cube(int offset, FHex h);

    //static FHex roffset_to_cube(int offset, FOffsetCoord h);

    //static FDoubledCoord rdoubled_from_cube(FHex h);

    //static FHex rdoubled_to_cube(FDoubledCoord h);



    const FOrientation layout_pointy = FOrientation(sqrt(3.0), sqrt(3.0) / 2.0, 0.0, 3.0 / 2.0, sqrt(3.0) / 3.0, -1.0 / 3.0, 0.0, 2.0 / 3.0, 0.5);
    const FOrientation layout_flat = FOrientation(3.0 / 2.0, 0.0, sqrt(3.0) / 2.0, sqrt(3.0), 2.0 / 3.0, 0.0, -1.0 / 3.0, sqrt(3.0) / 3.0, 0.0);
    static FPoint hex_to_pixel(FLayout layout, FHex h);

    static FFractionalHex pixel_to_hex(FLayout layout, FPoint p);

    static FPoint hex_corner_offset(FLayout layout, int corner);

    static TArray<FPoint> polygon_corners(FLayout layout, FHex h);


};