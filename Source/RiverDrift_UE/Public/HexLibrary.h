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
    int q;
    int r;
    int s;

    FHex(int q_, int r_, int s_) : q(q_), r(r_), s(s_) {
        if (q + r + s != 0) throw "q + r + s must be 0";
    }

    FHex() : q(0), r(0), s(0) {}

    //bool operator==(const FHex& Other) const {
    //    return q == Other.q && r == Other.r && s == Other.s;
    //}

    //FHex operator+(const FHex& Other) const {
    //    return FHex(q + Other.q, r + Other.r, s + Other.s);
    //}

    //FHex operator-(const FHex& Other) const {
    //    return FHex(q - Other.q, r - Other.r, s - Other.s);
    //}

    //String ToString() {
    //    return (ToString(q) + " " + ToString(r) + " " + ToString(s));
    //}
};

USTRUCT(BlueprintType)
//interchangable with vector2, but just what was used in this lib
struct FPoint
{

    GENERATED_BODY()

    double x;
    double y;
    FPoint(double x_, double y_) : x(x_), y(y_) {}
    FPoint() : x(0), y(0) {}
    //FPoint& operator=(const FPoint& other);

};


USTRUCT(BlueprintType)
struct FFractionalHex
{
    GENERATED_BODY()
 
    double q;
    double r;
    double s;

    FFractionalHex(double q_, double r_, double s_) : q(q_), r(r_), s(s_) {
        if (round(q + r + s) != 0) throw "q + r + s must be 0";
    }
    FFractionalHex() : q(0), r(0), s(0) {}
    //FFractionalHex& operator=(const FFractionalHex& other);
};


USTRUCT(BlueprintType)
struct FOffsetCoord
{
    GENERATED_BODY()

public:
    int col;
    int row;
    FOffsetCoord() : col(0), row(0) {}

    FOffsetCoord(int col_, int row_) : col(col_), row(row_) {}
    //FOffsetCoord& operator=(const FOffsetCoord& other);
        
};


USTRUCT(BlueprintType)
struct FDoubledCoord
{
    GENERATED_BODY()

    int col;
    int row;
    FDoubledCoord(int col_, int row_) : col(col_), row(row_) {}
    FDoubledCoord() : col(0), row(0) {}

    //FDoubledCoord& operator=(const FDoubledCoord& other);

};


USTRUCT(BlueprintType)
struct FOrientation
{
    GENERATED_BODY()

    double f0;
    double f1;
    double f2;
    double f3;
    double b0;
    double b1;
    double b2;
    double b3;
    double start_angle;
    FOrientation(double f0_, double f1_, double f2_, double f3_, double b0_, double b1_, double b2_, double b3_, double start_angle_) : f0(f0_), f1(f1_), f2(f2_), f3(f3_), b0(b0_), b1(b1_), b2(b2_), b3(b3_), start_angle(start_angle_) {}
    //FOrientation() : f0(0), f1(0), f2(0), f3(0), b0(0), b1(0), b2(0), b3(0), start_angle(0) {} //I want my default orientation to be pointy, feel free to rewrite this according to your needs
    FOrientation() : f0(sqrt(3.0)), f1(sqrt(3.0) / 2.0), f2(0.0), f3(3.0 / 2.0), b0(sqrt(3.0) / 3.0), b1( -1.0 / 3.0), b2(0.0), b3(2.0 / 3.0), start_angle(0.5) {} //copy pasted from the def of layout_pointy
    //FOrientation& operator=(const FOrientation& other);

};


USTRUCT(BlueprintType)
struct FLayout
{
    GENERATED_BODY()

    FOrientation orientation;
    FPoint size;
    FPoint origin;
    FLayout(FOrientation orientation_, FPoint size_, FPoint origin_) : orientation(orientation_), size(size_), origin(origin_) {}
    FLayout() : orientation(FOrientation()), size(.5, .5), origin(0, 0) {}
    //FLayout& operator=(const FLayout& other);

};



UCLASS()

class UHexLibrary : public UObject
{
    GENERATED_BODY()

public:

    //vars

    static const TArray<FHex> hex_directions;
    static const FOrientation layout_pointy;
    static const FOrientation layout_flat;

    static const int EVEN;
    static const int ODD;
    

    //static TArray<FHex> FHex GetHexDirections();
    
    static TArray<FHex> GetHexDirections();

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





    static FOffsetCoord offset_from_cube(FHex h, int offset = EVEN);

    static FHex offset_to_cube(FOffsetCoord h, int offset = EVEN);
    
    static FDoubledCoord doubled_from_cube(FHex h);
    
    static  FHex doubled_to_cube(FDoubledCoord h);
    //r is point top

    //static FOffsetCoord roffset_from_cube(int offset, FHex h);

    //static FHex roffset_to_cube(int offset, FOffsetCoord h);

    //static FDoubledCoord rdoubled_from_cube(FHex h);

    //static FHex rdoubled_to_cube(FDoubledCoord h);



    static FPoint hex_to_pixel(FLayout layout, FHex h);

    static FFractionalHex pixel_to_hex(FLayout layout, FPoint p);

    static FPoint hex_corner_offset(FLayout layout, int corner);

    static TArray<FPoint> polygon_corners(FLayout layout, FHex h);


};