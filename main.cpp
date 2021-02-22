//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass {N, S, W, E};

// Write your code here
class GPS{
  double latitude;
  Compass latitudeDirection;
  double longtitude;
  Compass longtitudeDirection;
public:
  GPS(double lat, Compass a, double longti, Compass b){
    latitude=lat;
    longtitude=longti;
    latitudeDirection=a;
    longtitudeDirection=b;
    if(lat>90 || lat<0){
      latitude=0;
      latitudeDirection= Compass::N;
      }
    if(longti>180 || longti<0){
      longtitude=0;
      longtitudeDirection=Compass::W;
      }
    if(a==Compass::W || a==Compass::E){
      latitudeDirection=Compass::N;
      }
    if(b==Compass::N || b==Compass::S){
      longtitudeDirection=Compass::W;
      }
    }
  GPS(double thelatitude, double thelongtitude){
    latitude=thelatitude;
    longtitude=thelongtitude;
    latitudeDirection=Compass::N;
    longtitudeDirection=Compass::W;
    if(thelatitude>90 || thelatitude<0){
      latitude=0;
      latitudeDirection=Compass::N;
      }
    if(thelongtitude>180 || thelongtitude<0){
      longtitude=0;
      longtitudeDirection=Compass::W; 
      } 
    }
    double getLatitude(){
      return latitude;
      }
    double getLongitude(){
      return longtitude;
      }
    Compass getLatitudeDirection(){
      return latitudeDirection;
      }
    Compass getLongitudeDirection(){
      return longtitudeDirection;
      }
  GPS(){
    latitude=0;
    latitudeDirection=Compass::N;
    longtitude=0;
    longtitudeDirection=Compass::W;
    }
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "GPS" ) {
    SECTION( "t1" ) {
        GPS c;
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t2" ) {
        GPS c{12.12, 50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t3" ) {
        GPS c{12.12, Compass::S, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::S );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t4" ) {
        GPS c{122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t5" ) {
        GPS c{122.12, 500.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t6" ) {
        GPS c{-122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t7" ) {
        GPS c{12.12, -50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t8" ) {
        GPS c{12.12, Compass::W, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t9" ) {
        GPS c{12.12, Compass::N, 50.34, Compass::N};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t10" ) {
        GPS c{-12.12, Compass::E, 540.34, Compass::N};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
}
//------------------------------
