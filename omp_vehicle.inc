#if defined _INC_omp_vehicle
	#endinput
#endif
#define _INC_omp_vehicle

/**
 * <library name="omp_vehicle" summary="open.mp vehicle functions.">
 *   <license>
 *     This Source Code Form is subject to the terms of the Mozilla Public License,
 *     v. 2.0. If a copy of the MPL was not distributed with this file, You can
 *     obtain one at http://mozilla.org/MPL/2.0/.
 *
 *     The original code is copyright (c) 2023, open.mp team and contributors.
 *   </license>
 *   <summary pawndoc="true">
 *     This library uses the enhanced <em>pawndoc.xsl</em> from
 *     <a href="https://github.com/pawn-lang/pawndoc">pawn-lang/pawndoc</a>.
 *     This XSL has features such as library and markdown support, and will not
 *     render this message when used.
 *   </summary>
 * </library>
 */

/// <p/>

#pragma tabsize 4

/**
 * <library>omp_vehicle</library>
 */
#if defined MAX_VEHICLES
	#if MAX_VEHICLES < 1 || MAX_VEHICLES > 2000
		#error MAX_VEHICLES must be >= 1 and <= 2000
	#endif

	const __MAX_VEHICLES                       = MAX_VEHICLES;
	#define __MAX_VEHICLES
#else
	const MAX_VEHICLES                         = 2000;
	#define MAX_VEHICLES                       2000
#endif

/**
 * <library>omp_vehicle</library>
 */
const INVALID_VEHICLE_ID                       = 0xFFFF;
#define INVALID_VEHICLE_ID                     65535

/// <p/>
/**
 * <library>omp_vehicle</library>
 */
#define CARMODTYPE: __TAG(CARMODTYPE):
enum CARMODTYPE:MAX_CARMODS
{
	UNKNOWN_CARMODTYPE                         = -1,
	CARMODTYPE_NONE                            = -1,
	CARMODTYPE_SPOILER,
	CARMODTYPE_HOOD,
	CARMODTYPE_ROOF,
	CARMODTYPE_SIDESKIRT,
	CARMODTYPE_LAMPS,
	CARMODTYPE_NITRO,
	CARMODTYPE_EXHAUST,
	CARMODTYPE_WHEELS,
	CARMODTYPE_STEREO,
	CARMODTYPE_HYDRAULICS,
	CARMODTYPE_FRONT_BUMPER,
	CARMODTYPE_REAR_BUMPER,
	CARMODTYPE_VENT_RIGHT,
	CARMODTYPE_VENT_LEFT,
	CARMODTYPE_FRONT_BULLBAR,
	CARMODTYPE_REAR_BULLBAR
}
static stock CARMODTYPE:_@CARMODTYPE() { return MAX_CARMODS; }

#define UNKNOWN_CARMODTYPE                     (CARMODTYPE:-1)
#define CARMODTYPE_NONE                        (CARMODTYPE:-1)
#define CARMODTYPE_SPOILER                     (CARMODTYPE:0)
#define CARMODTYPE_HOOD                        (CARMODTYPE:1)
#define CARMODTYPE_ROOF                        (CARMODTYPE:2)
#define CARMODTYPE_SIDESKIRT                   (CARMODTYPE:3)
#define CARMODTYPE_LAMPS                       (CARMODTYPE:4)
#define CARMODTYPE_NITRO                       (CARMODTYPE:5)
#define CARMODTYPE_EXHAUST                     (CARMODTYPE:6)
#define CARMODTYPE_WHEELS                      (CARMODTYPE:7)
#define CARMODTYPE_STEREO                      (CARMODTYPE:8)
#define CARMODTYPE_HYDRAULICS                  (CARMODTYPE:9)
#define CARMODTYPE_FRONT_BUMPER                (CARMODTYPE:10)
#define CARMODTYPE_REAR_BUMPER                 (CARMODTYPE:11)
#define CARMODTYPE_VENT_RIGHT                  (CARMODTYPE:12)
#define CARMODTYPE_VENT_LEFT                   (CARMODTYPE:13)
#define CARMODTYPE_FRONT_BULLBAR               (CARMODTYPE:14)
#define CARMODTYPE_REAR_BULLBAR                (CARMODTYPE:15)

// Backwards-compatibility.
#define VEHICLE_PARAMS: _:

/**
 * <library>omp_vehicle</library>
 */
const VEHICLE_PARAMS_UNSET = -1;

/**
 * <library>omp_vehicle</library>
 */
const VEHICLE_PARAMS_OFF = 0;

/**
 * <library>omp_vehicle</library>
 */
const VEHICLE_PARAMS_ON = 1;

/// <p/>
/**
 * <library>omp_vehicle</library>
 */
#define VEHICLE_MODEL_INFO: __TAG(VEHICLE_MODEL_INFO):
enum VEHICLE_MODEL_INFO:MAX_VEHICLE_MODEL_INFOS
{
	UNKNOWN_VEHICLE_MODEL_INFO                 = -1,
	VEHICLE_MODEL_INFO_SIZE                    = 1,
	VEHICLE_MODEL_INFO_FRONT_SEAT,
	VEHICLE_MODEL_INFO_REAR_SEAT,
	VEHICLE_MODEL_INFO_PETROL_CAP,
	VEHICLE_MODEL_INFO_WHEELS_FRONT,
	VEHICLE_MODEL_INFO_WHEELS_REAR,
	VEHICLE_MODEL_INFO_WHEELS_MID,
	// First so we don't have trailing commas.
#if __namemax > 31
	VEHICLE_MODEL_INFO_FRONT_BUMPER_Z,
	VEHICLE_MODEL_INFO_REAR_BUMPER_Z,
#endif
	VEHICLE_MODEL_INFO_FRONTSEAT = VEHICLE_MODEL_INFO_FRONT_SEAT,
	VEHICLE_MODEL_INFO_REARSEAT,
	VEHICLE_MODEL_INFO_PETROLCAP,
	VEHICLE_MODEL_INFO_WHEELSFRONT,
	VEHICLE_MODEL_INFO_WHEELSREAR,
	VEHICLE_MODEL_INFO_WHEELSMID,
	VEHICLE_MODEL_INFO_FRONT_BUMPER,
	VEHICLE_MODEL_INFO_REAR_BUMPER
}
static stock VEHICLE_MODEL_INFO:_@VEHICLE_MODEL_INFO() { return MAX_VEHICLE_MODEL_INFOS; }

#define UNKNOWN_VEHICLE_MODEL_INFO             (VEHICLE_MODEL_INFO:-1)
#define VEHICLE_MODEL_INFO_SIZE                (VEHICLE_MODEL_INFO:1)
#define VEHICLE_MODEL_INFO_FRONT_SEAT          (VEHICLE_MODEL_INFO:2)
#define VEHICLE_MODEL_INFO_REAR_SEAT           (VEHICLE_MODEL_INFO:3)
#define VEHICLE_MODEL_INFO_PETROL_CAP          (VEHICLE_MODEL_INFO:4)
#define VEHICLE_MODEL_INFO_WHEELS_FRONT        (VEHICLE_MODEL_INFO:5)
#define VEHICLE_MODEL_INFO_WHEELS_REAR         (VEHICLE_MODEL_INFO:6)
#define VEHICLE_MODEL_INFO_WHEELS_MID          (VEHICLE_MODEL_INFO:7)
#if __namemax > 31
#define VEHICLE_MODEL_INFO_FRONT_BUMPER_Z      (VEHICLE_MODEL_INFO:8)
#define VEHICLE_MODEL_INFO_REAR_BUMPER_Z       (VEHICLE_MODEL_INFO:9)
#endif
#define VEHICLE_MODEL_INFO_FRONTSEAT           (VEHICLE_MODEL_INFO:2)
#define VEHICLE_MODEL_INFO_REARSEAT            (VEHICLE_MODEL_INFO:3)
#define VEHICLE_MODEL_INFO_PETROLCAP           (VEHICLE_MODEL_INFO:4)
#define VEHICLE_MODEL_INFO_WHEELSFRONT         (VEHICLE_MODEL_INFO:5)
#define VEHICLE_MODEL_INFO_WHEELSREAR          (VEHICLE_MODEL_INFO:6)
#define VEHICLE_MODEL_INFO_WHEELSMID           (VEHICLE_MODEL_INFO:7)
#define VEHICLE_MODEL_INFO_FRONT_BUMPER        (VEHICLE_MODEL_INFO:8)
#define VEHICLE_MODEL_INFO_REAR_BUMPER         (VEHICLE_MODEL_INFO:9)

/// <p/>
/**
 * <library>omp_vehicle</library>
 */
#define VEHICLE_PANEL_STATUS: __TAG(VEHICLE_PANEL_STATUS):
enum VEHICLE_PANEL_STATUS:__VEHICLE_PANEL_STATUS
{
	UNKNOWN_VEHICLE_PANEL_STATUS               = -1,
	VEHICLE_PANEL_STATUS_NONE                  = 0
}
static stock VEHICLE_PANEL_STATUS:_@VEHICLE_PANEL_STATUS() { return __VEHICLE_PANEL_STATUS; }

#define UNKNOWN_VEHICLE_PANEL_STATUS           (VEHICLE_PANEL_STATUS:-1)
#define VEHICLE_PANEL_STATUS_NONE              (VEHICLE_PANEL_STATUS:0)

/// <p/>
/**
 * <library>omp_vehicle</library>
 */
#define VEHICLE_DOOR_STATUS: __TAG(VEHICLE_DOOR_STATUS):
enum VEHICLE_DOOR_STATUS:__VEHICLE_DOOR_STATUS (<<= 1)
{
	UNKNOWN_VEHICLE_DOOR_STATUS                = -1,
	VEHICLE_DOOR_STATUS_NONE                   = 0,
#if __namemax > 31
	VEHICLE_DOOR_STATUS_BONNET_OPEN            = 0x00000001,
	VEHICLE_DOOR_STATUS_BONNET_DAMAGED,
	VEHICLE_DOOR_STATUS_BONNET_MISSING,
	VEHICLE_DOOR_STATUS_HOOD_OPEN              = VEHICLE_DOOR_STATUS_BONNET_OPEN,
	VEHICLE_DOOR_STATUS_HOOD_DAMAGED,
	VEHICLE_DOOR_STATUS_HOOD_MISSING,
	VEHICLE_DOOR_STATUS_BOOT_OPEN              = 0x00000100,
	VEHICLE_DOOR_STATUS_BOOT_DAMAGED,
	VEHICLE_DOOR_STATUS_BOOT_MISSING,
	VEHICLE_DOOR_STATUS_TRUNK_OPEN             = VEHICLE_DOOR_STATUS_BOOT_OPEN,
	VEHICLE_DOOR_STATUS_TRUNK_DAMAGED,
	VEHICLE_DOOR_STATUS_TRUNK_MISSING,
	VEHICLE_DOOR_STATUS_FRONT_LEFT_OPEN        = 0x00010000,
	VEHICLE_DOOR_STATUS_FRONT_LEFT_DAMAGED,
	VEHICLE_DOOR_STATUS_FRONT_LEFT_MISSING,
	VEHICLE_DOOR_STATUS_DRIVER_OPEN            = VEHICLE_DOOR_STATUS_FRONT_LEFT_OPEN,
	VEHICLE_DOOR_STATUS_DRIVER_DAMAGED,
	VEHICLE_DOOR_STATUS_DRIVER_MISSING,
	VEHICLE_DOOR_STATUS_FRONT_RIGHT_OPEN       = 0x01000000,
	VEHICLE_DOOR_STATUS_FRONT_RIGHT_DAMAGED,
	VEHICLE_DOOR_STATUS_FRONT_RIGHT_MISSING,
	VEHICLE_DOOR_STATUS_PASSENGER_OPEN         = VEHICLE_DOOR_STATUS_FRONT_RIGHT_OPEN,
	VEHICLE_DOOR_STATUS_PASSENGER_DAMAGED,
	VEHICLE_DOOR_STATUS_PASSENGER_MISSING,
#endif
	CARDOOR_NONE                               = 0,
	CARDOOR_BONNET_OPEN                        = 0x00000001,
	CARDOOR_BONNET_DAMAGED,
	CARDOOR_BONNET_MISSING,
	CARDOOR_HOOD_OPEN                          = CARDOOR_BONNET_OPEN,
	CARDOOR_HOOD_DAMAGED,
	CARDOOR_HOOD_MISSING,
	CARDOOR_BOOT_OPEN                          = 0x00000100,
	CARDOOR_BOOT_DAMAGED,
	CARDOOR_BOOT_MISSING,
	CARDOOR_TRUNK_OPEN                         = CARDOOR_BOOT_OPEN,
	CARDOOR_TRUNK_DAMAGED,
	CARDOOR_TRUNK_MISSING,
	CARDOOR_FRONT_LEFT_OPEN                    = 0x00010000,
	CARDOOR_FRONT_LEFT_DAMAGED,
	CARDOOR_FRONT_LEFT_MISSING,
	CARDOOR_DRIVER_OPEN                        = CARDOOR_FRONT_LEFT_OPEN,
	CARDOOR_DRIVER_DAMAGED,
	CARDOOR_DRIVER_MISSING,
	CARDOOR_FRONT_RIGHT_OPEN                   = 0x01000000,
	CARDOOR_FRONT_RIGHT_DAMAGED,
	CARDOOR_FRONT_RIGHT_MISSING,
	CARDOOR_PASSENGER_OPEN                     = CARDOOR_FRONT_RIGHT_OPEN,
	CARDOOR_PASSENGER_DAMAGED,
	CARDOOR_PASSENGER_MISSING
}
static stock VEHICLE_DOOR_STATUS:_@VEHICLE_DOOR_STATUS() { return __VEHICLE_DOOR_STATUS; }

#define UNKNOWN_VEHICLE_DOOR_STATUS            (VEHICLE_DOOR_STATUS:-1)
#define VEHICLE_DOOR_STATUS_NONE               (VEHICLE_DOOR_STATUS:0)
#if __namemax > 31
#define VEHICLE_DOOR_STATUS_BONNET_OPEN        (VEHICLE_DOOR_STATUS:0x00000001)
#define VEHICLE_DOOR_STATUS_BONNET_DAMAGED     (VEHICLE_DOOR_STATUS:0x00000002)
#define VEHICLE_DOOR_STATUS_BONNET_MISSING     (VEHICLE_DOOR_STATUS:0x00000004)
#define VEHICLE_DOOR_STATUS_HOOD_OPEN          (VEHICLE_DOOR_STATUS:0x00000001)
#define VEHICLE_DOOR_STATUS_HOOD_DAMAGED       (VEHICLE_DOOR_STATUS:0x00000002)
#define VEHICLE_DOOR_STATUS_HOOD_MISSING       (VEHICLE_DOOR_STATUS:0x00000004)
#define VEHICLE_DOOR_STATUS_BOOT_OPEN          (VEHICLE_DOOR_STATUS:0x00000100)
#define VEHICLE_DOOR_STATUS_BOOT_DAMAGED       (VEHICLE_DOOR_STATUS:0x00000200)
#define VEHICLE_DOOR_STATUS_BOOT_MISSING       (VEHICLE_DOOR_STATUS:0x00000400)
#define VEHICLE_DOOR_STATUS_TRUNK_OPEN         (VEHICLE_DOOR_STATUS:0x00000100)
#define VEHICLE_DOOR_STATUS_TRUNK_DAMAGED      (VEHICLE_DOOR_STATUS:0x00000200)
#define VEHICLE_DOOR_STATUS_TRUNK_MISSING      (VEHICLE_DOOR_STATUS:0x00000400)
#define VEHICLE_DOOR_STATUS_FRONT_LEFT_OPEN    (VEHICLE_DOOR_STATUS:0x00010000)
#define VEHICLE_DOOR_STATUS_FRONT_LEFT_DAMAGED (VEHICLE_DOOR_STATUS:0x00020000)
#define VEHICLE_DOOR_STATUS_FRONT_LEFT_MISSING (VEHICLE_DOOR_STATUS:0x00040000)
#define VEHICLE_DOOR_STATUS_DRIVER_OPEN        (VEHICLE_DOOR_STATUS:0x00010000)
#define VEHICLE_DOOR_STATUS_DRIVER_DAMAGED     (VEHICLE_DOOR_STATUS:0x00020000)
#define VEHICLE_DOOR_STATUS_DRIVER_MISSING     (VEHICLE_DOOR_STATUS:0x00040000)
#define VEHICLE_DOOR_STATUS_FRONT_RIGHT_OPEN   (VEHICLE_DOOR_STATUS:0x01000000)
#define VEHICLE_DOOR_STATUS_FRONT_RIGHT_DAMAGED    (VEHICLE_DOOR_STATUS:0x02000000)
#define VEHICLE_DOOR_STATUS_FRONT_RIGHT_MISSING    (VEHICLE_DOOR_STATUS:0x04000000)
#define VEHICLE_DOOR_STATUS_PASSENGER_OPEN     (VEHICLE_DOOR_STATUS:0x01000000)
#define VEHICLE_DOOR_STATUS_PASSENGER_DAMAGED  (VEHICLE_DOOR_STATUS:0x02000000)
#define VEHICLE_DOOR_STATUS_PASSENGER_MISSING  (VEHICLE_DOOR_STATUS:0x04000000)
#endif
#define CARDOOR_NONE                           (VEHICLE_DOOR_STATUS:0)
#define CARDOOR_BONNET_OPEN                    (VEHICLE_DOOR_STATUS:0x00000001)
#define CARDOOR_BONNET_DAMAGED                 (VEHICLE_DOOR_STATUS:0x00000002)
#define CARDOOR_BONNET_MISSING                 (VEHICLE_DOOR_STATUS:0x00000004)
#define CARDOOR_HOOD_OPEN                      (VEHICLE_DOOR_STATUS:0x00000001)
#define CARDOOR_HOOD_DAMAGED                   (VEHICLE_DOOR_STATUS:0x00000002)
#define CARDOOR_HOOD_MISSING                   (VEHICLE_DOOR_STATUS:0x00000004)
#define CARDOOR_BOOT_OPEN                      (VEHICLE_DOOR_STATUS:0x00000100)
#define CARDOOR_BOOT_DAMAGED                   (VEHICLE_DOOR_STATUS:0x00000200)
#define CARDOOR_BOOT_MISSING                   (VEHICLE_DOOR_STATUS:0x00000400)
#define CARDOOR_TRUNK_OPEN                     (VEHICLE_DOOR_STATUS:0x00000100)
#define CARDOOR_TRUNK_DAMAGED                  (VEHICLE_DOOR_STATUS:0x00000200)
#define CARDOOR_TRUNK_MISSING                  (VEHICLE_DOOR_STATUS:0x00000400)
#define CARDOOR_FRONT_LEFT_OPEN                (VEHICLE_DOOR_STATUS:0x00010000)
#define CARDOOR_FRONT_LEFT_DAMAGED             (VEHICLE_DOOR_STATUS:0x00020000)
#define CARDOOR_FRONT_LEFT_MISSING             (VEHICLE_DOOR_STATUS:0x00040000)
#define CARDOOR_DRIVER_OPEN                    (VEHICLE_DOOR_STATUS:0x00010000)
#define CARDOOR_DRIVER_DAMAGED                 (VEHICLE_DOOR_STATUS:0x00020000)
#define CARDOOR_DRIVER_MISSING                 (VEHICLE_DOOR_STATUS:0x00040000)
#define CARDOOR_FRONT_RIGHT_OPEN               (VEHICLE_DOOR_STATUS:0x01000000)
#define CARDOOR_FRONT_RIGHT_DAMAGED            (VEHICLE_DOOR_STATUS:0x02000000)
#define CARDOOR_FRONT_RIGHT_MISSING            (VEHICLE_DOOR_STATUS:0x04000000)
#define CARDOOR_PASSENGER_OPEN                 (VEHICLE_DOOR_STATUS:0x01000000)
#define CARDOOR_PASSENGER_DAMAGED              (VEHICLE_DOOR_STATUS:0x02000000)
#define CARDOOR_PASSENGER_MISSING              (VEHICLE_DOOR_STATUS:0x04000000)

/// <p/>
/**
 * <library>omp_vehicle</library>
 */
#define VEHICLE_LIGHT_STATUS: __TAG(VEHICLE_LIGHT_STATUS):
enum VEHICLE_LIGHT_STATUS:__VEHICLE_LIGHT_STATUS
{
	UNKNOWN_VEHICLE_LIGHT_STATUS               = 0,
	VEHICLE_LIGHT_STATUS_NONE                  = 0,
#if __namemax > 31
	VEHICLE_LIGHT_STATUS_FRONT_LEFT_BROKEN     = 1,
	VEHICLE_LIGHT_STATUS_FRONT_RIGHT_BROKEN    = 4,
	VEHICLE_LIGHT_STATUS_DRIVER_BROKEN         = VEHICLE_LIGHT_STATUS_FRONT_LEFT_BROKEN,
	VEHICLE_LIGHT_STATUS_PASSENGER_BROKEN      = VEHICLE_LIGHT_STATUS_FRONT_RIGHT_BROKEN,
	VEHICLE_LIGHT_STATUS_REAR_BROKEN           = 64,
#endif
	CARLIGHT_FRONT_LEFT_BROKEN                 = 1,
	CARLIGHT_FRONT_RIGHT_BROKEN                = 4,
	CARLIGHT_DRIVER_BROKEN                     = CARLIGHT_FRONT_LEFT_BROKEN,
	CARLIGHT_PASSENGER_BROKEN                  = CARLIGHT_FRONT_RIGHT_BROKEN,
	CARLIGHT_REAR_BROKEN                       = 64
}
static stock VEHICLE_LIGHT_STATUS:_@VEHICLE_LIGHT_STATUS() { return __VEHICLE_LIGHT_STATUS; }

#define UNKNOWN_VEHICLE_LIGHT_STATUS           (VEHICLE_LIGHT_STATUS:0)
#define VEHICLE_LIGHT_STATUS_NONE              (VEHICLE_LIGHT_STATUS:0)
#if __namemax > 31
#define VEHICLE_LIGHT_STATUS_FRONT_LEFT_BROKEN (VEHICLE_LIGHT_STATUS:1)
#define VEHICLE_LIGHT_STATUS_FRONT_RIGHT_BROKEN    (VEHICLE_LIGHT_STATUS:4)
#define VEHICLE_LIGHT_STATUS_DRIVER_BROKEN     (VEHICLE_LIGHT_STATUS:1)
#define VEHICLE_LIGHT_STATUS_PASSENGER_BROKEN  (VEHICLE_LIGHT_STATUS:4)
#define VEHICLE_LIGHT_STATUS_REAR_BROKEN       (VEHICLE_LIGHT_STATUS:64)
#endif
#define CARLIGHT_FRONT_LEFT_BROKEN             (VEHICLE_LIGHT_STATUS:1)
#define CARLIGHT_FRONT_RIGHT_BROKEN            (VEHICLE_LIGHT_STATUS:4)
#define CARLIGHT_DRIVER_BROKEN                 (VEHICLE_LIGHT_STATUS:1)
#define CARLIGHT_PASSENGER_BROKEN              (VEHICLE_LIGHT_STATUS:4)
#define CARLIGHT_REAR_BROKEN                   (VEHICLE_LIGHT_STATUS:64)

/// <p/>
/**
 * <library>omp_vehicle</library>
 */
#define VEHICLE_TYRE_STATUS: __TAG(VEHICLE_TYRE_STATUS):
#define VEHICLE_TIRE_STATUS: __TAG(VEHICLE_TYRE_STATUS):
enum VEHICLE_TYRE_STATUS:__VEHICLE_TYRE_STATUS
{
	UNKNOWN_VEHICLE_TYRE_STATUS                = -1,
	VEHICLE_TYRE_STATUS_NONE                   = 0,
#if __namemax > 31
	VEHICLE_TYRE_STATUS_FRONT_LEFT_POPPED      = 8,
	VEHICLE_TYRE_STATUS_FRONT_RIGHT_POPPED     = 2,
	VEHICLE_TYRE_STATUS_REAR_LEFT_POPPED       = 4,
	VEHICLE_TYRE_STATUS_REAR_RIGHT_POPPED      = 1,
	VEHICLE_TIRE_STATUS_FRONT_LEFT_POPPED      = 8,
	VEHICLE_TIRE_STATUS_FRONT_RIGHT_POPPED     = 2,
	VEHICLE_TIRE_STATUS_REAR_LEFT_POPPED       = 4,
	VEHICLE_TIRE_STATUS_REAR_RIGHT_POPPED      = 1,
#endif
	CARTYRE_FRONT_LEFT_POPPED                  = 8,
	CARTYRE_FRONT_RIGHT_POPPED                 = 2,
	CARTYRE_REAR_LEFT_POPPED                   = 4,
	CARTYRE_REAR_RIGHT_POPPED                  = 1,
	CARTIRE_FRONT_LEFT_POPPED                  = 8,
	CARTIRE_FRONT_RIGHT_POPPED                 = 2,
	CARTIRE_REAR_LEFT_POPPED                   = 4,
	CARTIRE_REAR_RIGHT_POPPED                  = 1
}
static stock VEHICLE_TYRE_STATUS:_@VEHICLE_TYRE_STATUS() { return __VEHICLE_TYRE_STATUS; }

#define UNKNOWN_VEHICLE_TYRE_STATUS            (VEHICLE_TYRE_STATUS:-1)
#define VEHICLE_TYRE_STATUS_NONE               (VEHICLE_TYRE_STATUS:0)
#if __namemax > 31
#define VEHICLE_TYRE_STATUS_FRONT_LEFT_POPPED  (VEHICLE_TYRE_STATUS:8)
#define VEHICLE_TYRE_STATUS_FRONT_RIGHT_POPPED (VEHICLE_TYRE_STATUS:2)
#define VEHICLE_TYRE_STATUS_REAR_LEFT_POPPED   (VEHICLE_TYRE_STATUS:4)
#define VEHICLE_TYRE_STATUS_REAR_RIGHT_POPPED  (VEHICLE_TYRE_STATUS:1)
#define VEHICLE_TIRE_STATUS_FRONT_LEFT_POPPED  (VEHICLE_TYRE_STATUS:8)
#define VEHICLE_TIRE_STATUS_FRONT_RIGHT_POPPED (VEHICLE_TYRE_STATUS:2)
#define VEHICLE_TIRE_STATUS_REAR_LEFT_POPPED   (VEHICLE_TYRE_STATUS:4)
#define VEHICLE_TIRE_STATUS_REAR_RIGHT_POPPED  (VEHICLE_TYRE_STATUS:1)
#endif
#define CARTYRE_FRONT_LEFT_POPPED              (VEHICLE_TYRE_STATUS:8)
#define CARTYRE_FRONT_RIGHT_POPPED             (VEHICLE_TYRE_STATUS:2)
#define CARTYRE_REAR_LEFT_POPPED               (VEHICLE_TYRE_STATUS:4)
#define CARTYRE_REAR_RIGHT_POPPED              (VEHICLE_TYRE_STATUS:1)
#define CARTIRE_FRONT_LEFT_POPPED              (VEHICLE_TYRE_STATUS:8)
#define CARTIRE_FRONT_RIGHT_POPPED             (VEHICLE_TYRE_STATUS:2)
#define CARTIRE_REAR_LEFT_POPPED               (VEHICLE_TYRE_STATUS:4)
#define CARTIRE_REAR_RIGHT_POPPED              (VEHICLE_TYRE_STATUS:1)

/// <p/>
/**
 * <library>omp_vehicle</library>
 */
#define LANDING_GEAR_STATE: __TAG(LANDING_GEAR_STATE):
enum LANDING_GEAR_STATE:__LANDING_GEAR_STATE
{
	LANDING_GEAR_STATE_DOWN = 0,
	LANDING_GEAR_STATE_UP
}
static stock LANDING_GEAR_STATE:_@LANDING_GEAR_STATE() { return __LANDING_GEAR_STATE; }

#define LANDING_GEAR_STATE_DOWN                (LANDING_GEAR_STATE:0)
#define LANDING_GEAR_STATE_UP                  (LANDING_GEAR_STATE:1)

/*
                                                                           
    888b      88                       88                                      
    8888b     88                ,d     ""                                      
    88 `8b    88                88                                             
    88  `8b   88  ,adPPYYba,  MM88MMM  88  8b       d8   ,adPPYba,  ,adPPYba,  
    88   `8b  88  ""     `Y8    88     88  `8b     d8'  a8P_____88  I8[    ""  
    88    `8b 88  ,adPPPPP88    88     88   `8b   d8'   8PP"""""""   `"Y8ba,   
    88     `8888  88,    ,88    88,    88    `8b,d8'    "8b,   ,aa  aa    ]8I  
    88      `888  `"8bbdP"Y8    "Y888  88      "8"       `"Ybbd8"'  `"YbbdP"'  
                                                                           
                                                                           

*/

/**
 * <library>omp_vehicle</library>
 * <summary>Adds a 'static' vehicle (models are pre-loaded for players) to the gamemode.</summary>
 * <param name="modelid">The <a href="https://www.open.mp/docs/scripting/resources/vehicleid">Model ID</a> for the
 * vehicle</param>
 * <param name="spawnX">The x coordinate of the spawnpoint of this vehicle</param>
 * <param name="spawnY">The y coordinate of the spawnpoint of this vehicle</param>
 * <param name="spawnZ">The z coordinate of the spawnpoint of this vehicle</param>
 * <param name="angle">Direction of vehicle - angle</param>
 * <param name="colour1">The primary <a href="https://www.open.mp/docs/scripting/resources/vehiclecolorid">colour ID</a>. <b><c>-1</c></b>
 * for random (random colour chosen by client)</param>
 * <param name="colour2">The secondary <a href="https://www.open.mp/docs/scripting/resources/vehiclecolorid">colour ID</a>.
 * <b><c>-1</c></b> for random (random colour chosen by client)</param>
 * <returns>
 *   <ul>
 *     <li>The vehicle ID of the vehicle created (between <b><c>1</c></b> and <b><c>MAX_VEHICLES</c></b>).</li>
 *     <li><b><c>INVALID_VEHICLE_ID</c></b> (<b><c>65535</c></b>) if vehicle was not created (vehicle
 * limit reached or invalid vehicle model ID passed).</li>
 *   </ul>
 * </returns>
 * <remarks>Can only be used when the server first starts (under <a href="#OnGameModeInit">OnGameModeInit</a>).</remarks>
 * <seealso name="AddStaticVehicleEx" />
 * <seealso name="CreateVehicle" />
 * <seealso name="DestroyVehicle" />
 */
native AddStaticVehicle(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2);

/**
 * <library>omp_vehicle</library>
 * <summary>Adds a 'static' vehicle (models are pre-loaded for players)to the gamemode.  Differs from
 * <a href="#AddStaticVehicle">AddStaticVehicle</a> in only one way: allows a respawn time to be set
 * for when the vehicle is left unoccupied by the driver.</summary>
 * <param name="modelid">The <a href="https://www.open.mp/docs/scripting/resources/vehicleid">Model ID</a> for the
 * vehicle</param>
 * <param name="spawnX">The x coordinate of the spawnpoint of this vehicle</param>
 * <param name="spawnY">The y coordinate of the spawnpoint of this vehicle</param>
 * <param name="spawnZ">The z coordinate of the spawnpoint of this vehicle</param>
 * <param name="angle">Direction of vehicle - angle</param>
 * <param name="colour1">The primary <a href="https://www.open.mp/docs/scripting/resources/vehiclecolorid">colour ID</a>. <b><c>-1</c></b>
 * for random (random colour chosen by client)</param>
 * <param name="colour2">The secondary <a href="https://www.open.mp/docs/scripting/resources/vehiclecolorid">colour ID</a>.
 * <b><c>-1</c></b> for random (random colour chosen by client)</param>
 * <param name="respawnDelay">The delay until the car is respawned without a driver, in seconds</param>
 * <param name="addSiren"><b>Added in 0.3.7; will not work in earlier versions.</b> Enables the vehicle
 * to have a siren, providing the vehicle has a horn (optional=<b><c>0</c></b>)</param>
 * <returns>
 *   <ul>
 *     <li>The vehicle ID of the vehicle created (between <b><c>1</c></b> and <b><c>MAX_VEHICLES</c></b>).</li>
 *     <li><b><c>INVALID_VEHICLE_ID</c></b> (<b><c>65535</c></b>) if vehicle was not created (vehicle
 * limit reached or invalid vehicle model ID passed).</li>
 *   </ul>
 * </returns>
 * <remarks>Can only be used when the server first starts (under <a href="#OnGameModeInit">OnGameModeInit</a>).</remarks>
 * <seealso name="AddStaticVehicle" />
 * <seealso name="CreateVehicle" />
 * <seealso name="DestroyVehicle" />
 */
native AddStaticVehicleEx(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, bool:addSiren = false);

/**
 * <library>omp_vehicle</library>
 * <summary>Creates a vehicle in the world.  Can be used in place of <a href="#AddStaticVehicleEx">AddStaticVehicleEx</a>
 * at any time in the script.</summary>
 * <param name="modelid">The <a href="https://www.open.mp/docs/scripting/resources/vehicleid">model</a> for the vehicle</param>
 * <param name="spawnX">The x coordinate for the vehicle</param>
 * <param name="spawnY">The y coordinate for the vehicle</param>
 * <param name="spawnZ">The z coordinate for the vehicle</param>
 * <param name="angle">The facing angle for the vehicle</param>
 * <param name="colour1">The primary <a href="https://www.open.mp/docs/scripting/resources/vehiclecolorid">colour ID</a></param>
 * <param name="colour2">The secondary <a href="https://www.open.mp/docs/scripting/resources/vehiclecolorid">colour ID</a></param>
 * <param name="respawnDelay">The delay until the car is respawned without a driver in <b>seconds</b>.
 *  Using <b><c>-1</c></b> will prevent the vehicle from respawning</param>
 * <param name="addSiren"><b>Added in 0.3.7; will not work in earlier versions</b>.  Enables the vehicle
 * to have a siren, providing the vehicle has a horn (optional=<b><c>false</c></b>)</param>
 * <seealso name="DestroyVehicle" />
 * <seealso name="AddStaticVehicle" />
 * <seealso name="AddStaticVehicleEx" />
 * <seealso name="GetVehicleParamsSirenState" />
 * <seealso name="OnVehicleSpawn" />
 * <seealso name="OnVehicleSirenStateChange" />
 * <remarks>Trains can only be added with AddStaticVehicle and AddStaticVehicleEx.</remarks>
 * <returns>
 *   The vehicle ID of the vehicle created (<b><c>1</c></b> to <b><c>MAX_VEHICLES</c></b>).<br />
 *   <b><c>INVALID_VEHICLE_ID (65535)</c></b> if vehicle was not created (vehicle limit reached or invalid
 * vehicle model ID passed).
 * </returns>
 */
native CreateVehicle(modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay, bool:addSiren = false);

/**
 * <library>omp_vehicle</library>
 * <summary>Destroy a vehicle.  It will disappear instantly.</summary>
 * <param name="vehicleid">The ID of the vehicle to destroy</param>
 * <seealso name="CreateVehicle" />
 * <seealso name="RemovePlayerFromVehicle" />
 * <seealso name="SetVehicleToRespawn" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The vehicle does not exist.
 * </returns>
 */
native bool:DestroyVehicle(vehicleid);

/**
 * <library>omp_vehicle</library>
 * <summary>Checks if a vehicle is streamed in for a player.  Only nearby vehicles are streamed in (visible)
 * for a player.</summary>
 * <param name="vehicleid">The ID of the vehicle to check</param>
 * <param name="playerid">The ID of the player to check</param>
 * <seealso name="IsPlayerStreamedIn" />
 * <seealso name="OnVehicleStreamIn" />
 * <seealso name="OnVehicleStreamOut" />
 * <seealso name="OnPlayerStreamIn" />
 * <seealso name="OnPlayerStreamOut" />
 * <returns>
 *   <b><c>0</c></b>: Vehicle is not streamed in for the player, or the function failed to execute (player
 * and/or vehicle do not exist).<br />
 *   <b><c>1</c></b>: Vehicle is streamed in for the player.
 * </returns>
 */
native bool:IsVehicleStreamedIn(vehicleid, playerid);

/**
 * <library>omp_vehicle</library>
 * <summary>Gets the position of a vehicle.</summary>
 * <param name="vehicleid">The ID of the vehicle to get the position of</param>
 * <param name="x">A float variable in which to store the x coordinate, passed by reference</param>
 * <param name="y">A float variable in which to store the y coordinate, passed by reference</param>
 * <param name="z">A float variable in which to store the z coordinate, passed by reference</param>
 * <seealso name="GetVehicleDistanceFromPoint" />
 * <seealso name="SetVehiclePos" />
 * <seealso name="GetVehicleZAngle" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The vehicle specified does not exist.
 * </returns>
 */
native bool:GetVehiclePos(vehicleid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_vehicle</library>
 * <summary>Set a vehicle's position.</summary>
 * <param name="vehicleid">Vehicle ID that you want set new position</param>
 * <param name="x">The x coordinate to position the vehicle at</param>
 * <param name="y">The y coordinate to position the vehicle at</param>
 * <param name="z">The z coordinate to position the vehicle at</param>
 * <seealso name="SetPlayerPos" />
 * <seealso name="GetVehiclePos" />
 * <seealso name="SetVehicleZAngle" />
 * <remarks>An empty vehicle will not fall after being teleported into the air.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The vehicle specified does not exist.
 * </returns>
 */
native bool:SetVehiclePos(vehicleid, Float:x, Float:y, Float:z);

/**
 * <library>omp_vehicle</library>
 * <summary>Get the rotation of a vehicle on the z axis (yaw).</summary>
 * <param name="vehicleid">The ID of the vehicle to get the z angle of</param>
 * <param name="angle">A float variable in which to store the z rotation, passed by reference</param>
 * <seealso name="GetVehicleRotationQuat" />
 * <seealso name="GetVehicleRotation" />
 * <seealso name="SetVehicleZAngle" />
 * <seealso name="GetVehiclePos" />
 * <seealso name="GetPlayerFacingAngle" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the vehicle does not exist.
 * </returns>
 */
native bool:GetVehicleZAngle(vehicleid, &Float:angle);

/**
 * <library>omp_vehicle</library>
 * <summary>Returns a vehicle's rotation on all axes as a quaternion.</summary>
 * <param name="vehicleid">The ID of the vehicle to get the rotation of</param>
 * <param name="w">A float variable in which to store the first quaternion angle, passed by reference</param>
 * <param name="x">A float variable in which to store the second quaternion angle, passed by reference</param>
 * <param name="y">A float variable in which to store the third quaternion angle, passed by reference</param>
 * <param name="z">A float variable in which to store the fourth quaternion angle, passed by reference</param>
 * <seealso name="GetVehicleZAngle" />
 * <remarks>
 *   <b>To euler:</b><br />
 *   <code>
 *     // GetVehicleRotation Created by IllidanS4<br />
 *     stock GetVehicleRotation(vehicleid, &amp;Float:rx, &amp;Float:ry, &amp;Float:rz)<br />
 *     {<br />
 *         new Float:qw, Float:qx, Float:qy, Float:qz;<br />
 *         GetVehicleRotationQuat(vehicleid, qw, qx, qy, qz);<br />
 *         rx = asin((2 * qy * qz) - (2 * qx * qw));<br />
 *         ry = -atan2((qx * qz) + (qy * qw), 0.5 - (qx * qx) - (qy * qy));<br />
 *         rz = -atan2((qx * qy) + (qz * qw), 0.5 - (qx * qx) - (qz * qz));<br />
 *     }
 *   </code>
 * </remarks>
 * <remarks>There is no 'set' variation of this function; you can not SET a vehicle's rotation (apart
 * from the <a href="#SetVehicleZAngle">z angle</a>) </remarks>
 * <remarks>This function may return incorrect values for unoccupied vehicles.  The reason is that the
 * third row of the vehicle's internal rotation matrix gets corrupted if it gets updated while unoccupied.
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the vehicle specified does not exist.
 * </returns>
 */
native bool:GetVehicleRotationQuat(vehicleid, &Float:w, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_vehicle</library>
 * <summary>This function can be used to calculate the distance (as a float) between a vehicle and another
 * map coordinate.  This can be useful to detect how far a vehicle away is from a location.</summary>
 * <param name="vehicleid">The ID of the vehicle to calculate the distance for</param>
 * <param name="x">The x map coordinate</param>
 * <param name="y">The y map coordinate</param>
 * <param name="z">The z map coordinate</param>
 * <seealso name="GetPlayerDistanceFromPoint" />
 * <seealso name="GetVehiclePos" />
 * <returns>A float containing the distance from the point specified in the coordinates.</returns>
 */
native Float:GetVehicleDistanceFromPoint(vehicleid, Float:x, Float:y, Float:z);

/**
 * <library>omp_vehicle</library>
 * <summary>Set the z rotation (yaw) of a vehicle.</summary>
 * <param name="vehicleid">The ID of the vehicle to set the rotation of</param>
 * <param name="angle">The z angle to set</param>
 * <seealso name="GetVehicleZAngle" />
 * <seealso name="SetVehiclePos" />
 * <remarks>A vehicle's x and y (pitch and roll) rotation will be reset when this function is used.
 *  The x and y rotations can not be set.</remarks>
 * <remarks>This function does not work on unoccupied vehicles.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The vehicle specified does not exist.
 * </returns>
 */
native bool:SetVehicleZAngle(vehicleid, Float:angle);

/**
 * <library>omp_vehicle</library>
 * <summary>Set the parameters of a vehicle for a player.</summary>
 * <param name="vehicle">The ID of the vehicle to set the parameters of</param>
 * <param name="playerid">The ID of the player to set the vehicle's parameters for</param>
 * <param name="objective"><b><c>0</c></b> to disable the objective or <b><c>1</c></b> to show it.
 * This is a bobbing yellow arrow above the vehicle</param>
 * <param name="doors"><b><c>0</c></b> to unlock the doors or <b><c>1</c></b> to lock them</param>
 * <seealso name="SetVehicleParamsEx" />
 * <remarks>Vehicles must be respawned for the 'objective' to be removed.  This can be circumvented
 * somewhat using Get/SetVehicleParamsEx which do not require the vehicle to be respawned.  It is worth
 * noting however that the object will be disabled on a global scale, and this is only useful if only
 * one player has the vehicle as an objective.</remarks>
 * <remarks>Since <b>0.3a</b> you will have to reapply this function when <a href="#OnVehicleStreamIn">OnVehicleStreamIn</a>
 * is called.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player and/or vehicle specified do not exist.
 * </returns>
 */
native bool:SetVehicleParamsForPlayer(vehicleid, playerid, objective = -1, doors = -1);

/**
 * <library>omp_vehicle</library>
 * <summary>Use this function before any player connects (<a href="#OnGameModeInit">OnGameModeInit</a>)
 * to tell all clients that the script will control vehicle engines and lights.  This prevents the game
 * automatically turning the engine on/off when players enter/exit vehicles and headlights automatically
 * coming on when it is dark.</summary>
 * <seealso name="SetVehicleParamsEx" />
 * <seealso name="GetVehicleParamsEx" />
 * <seealso name="SetVehicleParamsForPlayer" />
 * <remarks>Is it not possible to reverse this function after it has been used.  You must either use
 * it or not use it.</remarks>
 * <returns>This function always returns <b><c>1</c></b>.  It cannot fail to execute.</returns>
 */
native void:ManualVehicleEngineAndLights();

/**
 * <library>omp_vehicle</library>
 * <summary>Sets a vehicle's parameters for all players.</summary>
 * <param name="vehicleid">The ID of the vehicle to set the parameters of</param>
 * <param name="engine">Engine status. <b><c>0</c></b> - Off, <b><c>1</c></b> - On</param>
 * <param name="lights">Light status. <b><c>0</c></b> - Off, <b><c>1</c></b> - On</param>
 * <param name="alarm">Vehicle alarm status.  If on, the alarm starts. <b><c>0</c></b> - Off, <b><c>1</c></b>
 * - On</param>
 * <param name="doors">Door lock status. <b><c>0</c></b> - Unlocked, <b><c>1</c></b> - Locked</param>
 * <param name="bonnet">Bonnet (hood) status. <b><c>0</c></b> - Closed, <b><c>1</c></b> - Open</param>
 * <param name="boot">Boot/trunk status. <b><c>0</c></b> - Closed, <b><c>1</c></b> - Open</param>
 * <param name="objective">Toggle the objective arrow above the vehicle. <b><c>0</c></b> - Off, <b><c>1</c></b>
 * - On</param>
 * <seealso name="GetVehicleParamsEx" />
 * <seealso name="SetVehicleParamsForPlayer" />
 * <seealso name="UpdateVehicleDamageStatus" />
 * <remarks>The alarm will not reset when finished, you'll need to reset it by yourself with this function.
 * </remarks>
 * <remarks>Lights also operate during the day (Only when <a href="#ManualVehicleEngineAndLights">ManualVehicleEngineAndLights</a>
 * is enabled). </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the vehicle does not exist.
 * </returns>
 */
native bool:SetVehicleParamsEx(vehicleid, engine = -1, lights = -1, alarm = -1, doors = -1, bonnet = -1, boot = -1, objective = -1);

/**
 * <library>omp_vehicle</library>
 * <summary>Gets a vehicle's parameters.</summary>
 * <param name="vehicleid">The ID of the vehicle to get the parameters from</param>
 * <param name="engine">Get the engine status.  If <b><c>1</c></b>, the engine is running.</param>
 * <param name="lights">Get the vehicle's lights' state.  If <b><c>1</c></b> the lights are on</param>
 * <param name="alarm">Get the vehicle's alarm state.  If <b><c>1</c></b> the alarm is (or was) sounding</param>
 * <param name="doors">Get the lock status of the doors.  If <b><c>1</c></b> the doors are locked</param>
 * <param name="bonnet">Get the bonnet/hood status.  If <b><c>1</c></b>, it's open</param>
 * <param name="boot">Get the boot/trunk status. <b><c>1</c></b> means it is open</param>
 * <param name="objective">Get the objective status. <b><c>1</c></b> means the objective is on</param>
 * <seealso name="SetVehicleParamsEx" />
 * <remarks>If a parameter is unset (SetVehicleParamsEx not used beforehand) the value will be <b><c>-1</c></b>
 * ('unset').</remarks>
 */
native bool:GetVehicleParamsEx(vehicleid, &engine = -1, &lights = -1, &alarm = -1, &doors = -1, &bonnet = -1, &boot = -1, &objective = -1);

/**
 * <library>omp_vehicle</library>
 */
native bool:SetVehicleParamsSirenState(vehicleid, bool:enabled);

/**
 * <library>omp_vehicle</library>
 * <summary>Returns a vehicle's siren state (on/off).</summary>
 * <param name="vehicleid">The ID of the vehicle to get the siren state of</param>
 * <seealso name="OnVehicleSirenStateChange" />
 * <returns><b><c>-1</c></b> if unset (off), <b><c>0</c></b> if off, <b><c>1</c></b> if on</returns>
 */
native GetVehicleParamsSirenState(vehicleid);

/**
 * <library>omp_vehicle</library>
 * <summary>Allows you to open and close the doors of a vehicle.</summary>
 * <param name="vehicleid">The ID of the vehicle to set the door state of</param>
 * <param name="frontLeft">The state of the driver's door. <b><c>1</c></b> to open, <b><c>0</c></b>
 * to close</param>
 * <param name="frontRight">The state of the passenger door. <b><c>1</c></b> to open, <b><c>0</c></b>
 * to close</param>
 * <param name="rearLeft">The state of the rear left door (if available). <b><c>1</c></b> to open, <b><c>0</c></b>
 * to close</param>
 * <param name="rearRight">The state of the rear right door (if available). <b><c>1</c></b> to open,
 * <b><c>0</c></b> to close</param>
 * <seealso name="GetVehicleParamsCarDoors" />
 * <seealso name="SetVehicleParamsCarWindows" />
 * <seealso name="GetVehicleParamsCarWindows" />
 * <remarks><b><c>1</c></b> is open, <b><c>0</c></b> is closed</remarks>
 */
native bool:SetVehicleParamsCarDoors(vehicleid, frontLeft = -1, frontRight = -1, rearLeft = -1, rearRight = -1);

/**
 * <library>omp_vehicle</library>
 * <summary>Allows you to retrieve the current state of a vehicle's doors.</summary>
 * <param name="vehicleid">The ID of the vehicle</param>
 * <param name="frontLeft">The integer to save the state of the driver's door to</param>
 * <param name="frontRight">The integer to save the state of the passenger's door to</param>
 * <param name="rearLeft">The integer to save the state of the rear left door to (if available)</param>
 * <param name="rearRight">The integer to save the state of the rear right door to (if available)</param>
 * <seealso name="SetVehicleParamsCarDoors" />
 * <seealso name="SetVehicleParamsCarWindows" />
 * <seealso name="GetVehicleParamsCarWindows" />
 * <remarks>The values returned in each variable are as follows: <b><c>-1</c></b> if not set, <b><c>0</c></b>
 * if closed, <b><c>1</c></b> if open.</remarks>
 */
native bool:GetVehicleParamsCarDoors(vehicleid, &frontLeft = -1, &frontRight = -1, &rearLeft = -1, &rearRight = -1);

/**
 * <library>omp_vehicle</library>
 * <summary>Allows you to open and close the windows of a vehicle.</summary>
 * <param name="vehicleid">The ID of the vehicle to set the window state of</param>
 * <param name="frontLeft">The state of the driver's window. <b><c>0</c></b> to open, <b><c>1</c></b>
 * to close</param>
 * <param name="frontRight">The state of the passenger window. <b><c>0</c></b> to open, <b><c>1</c></b>
 * to close</param>
 * <param name="rearLeft">The state of the rear left window (if available). <b><c>0</c></b> to open,
 * <b><c>1</c></b> to close</param>
 * <param name="rearRight">The state of the rear right window (if available). <b><c>0</c></b> to open,
 * <b><c>1</c></b> to close</param>
 * <seealso name="SetVehicleParamsCarDoors" />
 * <seealso name="GetVehicleParamsCarDoors" />
 * <seealso name="GetVehicleParamsCarWindows" />
 */
native bool:SetVehicleParamsCarWindows(vehicleid, frontLeft = -1, frontRight = -1, rearLeft = -1, rearRight = -1);

/**
 * <library>omp_vehicle</library>
 * <summary>Allows you to retrieve the current state of a vehicle's windows.</summary>
 * <param name="vehicleid">The ID of the vehicle</param>
 * <param name="frontLeft">The integer to save the state of the drivers window to</param>
 * <param name="frontRight">The integer to save the state of the passengers window to</param>
 * <param name="rearLeft">The integer to save the state of the rear left window to (if available)</param>
 * <param name="rearRight">The integer to save the state of the rear right window to (if available)</param>
 * <seealso name="SetVehicleParamsCarWindows" />
 * <seealso name="GetVehicleParamsCarDoors" />
 * <seealso name="SetVehicleParamsCarDoors" />
 * <remarks>The values returned in each variable are as follows: <b><c>-1</c></b> if not set, <b><c>0</c></b>
 * if closed, <b><c>1</c></b> if open.</remarks>
 * <returns>The vehicle's windows state is stored in the specified variables.</returns>
 */
native bool:GetVehicleParamsCarWindows(vehicleid, &frontLeft = -1, &frontRight = -1, &rearLeft = -1, &rearRight = -1);

/**
 * <library>omp_vehicle</library>
 * <summary>Sets a vehicle back to the position at where it was created.</summary>
 * <param name="vehicleid">The ID of the vehicle to respawn</param>
 * <seealso name="CreateVehicle" />
 * <seealso name="DestroyVehicle" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The vehicle does not exist.
 * </returns>
 */
native bool:SetVehicleToRespawn(vehicleid);

/**
 * <library>omp_vehicle</library>
 * <summary>Links a vehicle to an interior.  Vehicles can only be seen by players in the same interior
 * (<a href="#SetPlayerInterior">SetPlayerInterior</a>).</summary>
 * <param name="vehicleid">The ID of the vehicle to link to an interior</param>
 * <param name="interiorid">The <a href="https://www.open.mp/docs/scripting/resources/interiorids">Interior ID</a> to
 * link it to</param>
 * <seealso name="SetVehicleVirtualWorld" />
 * <seealso name="SetPlayerInterior" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the vehicle does not exist.<br />
 * </returns>
 */
native bool:LinkVehicleToInterior(vehicleid, interiorid);

/**
 * <library>omp_vehicle</library>
 * <summary>Adds a 'component' (often referred to as a 'mod' (modification)) to a vehicle.  Valid components
 * can be found <a href="https://www.open.mp/docs/scripting/resources/carcomponentid">here</a>.</summary>
 * <param name="vehicleid">The ID of the vehicle to add the component to.  Not to be confused with <a
 * href="https://sampwiki.blast.hk/wiki/Confuse_modelid">modelid</a></param>
 * <param name="component">The <a href="https://www.open.mp/docs/scripting/resources/carcomponentid">ID of the component</a>
 * to add to the vehicle</param>
 * <returns>
 *   <ul>
 *     <li><b><c>0</c></b> - The component was not added because the vehicle does not exist.</li>
 *     <li><b><c>1</c></b> - The component was successfully added to the vehicle.</li>
 *   </ul>
 * </returns>
 * <remarks>Using an invalid <a href="https://www.open.mp/docs/scripting/resources/carcomponentid">component ID</a>
 * crashes the player's game.  There are no internal checks for this.</remarks>
 * <seealso name="RemoveVehicleComponent" />
 * <seealso name="GetVehicleComponentInSlot" />
 * <seealso name="GetVehicleComponentType" />
 * <seealso name="OnVehicleMod" />
 * <seealso name="OnEnterExitModShop" />
 */
native bool:AddVehicleComponent(vehicleid, component);

/**
 * <library>omp_vehicle</library>
 * <summary>Remove a component from a vehicle.</summary>
 * <param name="vehicleid">ID of the vehicle.</param>
 * <param name="component">ID of the <a href="https://www.open.mp/docs/scripting/resources/carcomponentid">component</a>
 * to remove.</param>
 * <seealso name="AddVehicleComponent" />
 * <seealso name="GetVehicleComponentInSlot" />
 * <seealso name="GetVehicleComponentType" />
 * <seealso name="OnVehicleMod" />
 * <seealso name="OnEnterExitModShop" />
 */
native bool:RemoveVehicleComponent(vehicleid, component);

/**
 * <library>omp_vehicle</library>
 * <summary>Is this component legal on this vehicle?</summary>
 * <param name="vehicleid">ID of the vehicle.</param>
 * <param name="component">ID of the <a href="https://www.open.mp/docs/scripting/resources/carcomponentid">component</a>
 * to check.</param>
 * <seealso name="AddVehicleComponent" />
 * <seealso name="GetVehicleComponentInSlot" />
 * <seealso name="GetVehicleComponentType" />
 * <seealso name="OnVehicleMod" />
 * <seealso name="OnEnterExitModShop" />
 */
native bool:VehicleCanHaveComponent(vehicleid, componentid);

/**
 * <library>omp_vehicle</library>
 * <summary>Gets the number of seats for a vehicle model.</summary>
 * <param name="vehicleid">ID of the vehicle model.</param>
 * <returns>
 *   <b><c>number of seats</c></b>: The number of seats as an integer.<br />
 * </returns>
 */
native GetVehicleSeats(vehicleid);

/**
 * <library>omp_vehicle</library>
 * <summary>Gets the number of seats for a vehicle model.</summary>
 * <param name="modelid">The ID of the vehicle model.</param>
 * <returns>
 *   <b><c>number of seats</c></b>: The number of seats as an integer.<br />
 * </returns>
 */
native GetVehicleMaxPassengers(vehicleid) = GetVehicleSeats;

/**
 * <library>omp_vehicle</library>
 * <summary>Change a vehicle's primary and secondary colours.</summary>
 * <param name="vehicleid">The ID of the vehicle to change the colours of</param>
 * <param name="color1">The new vehicle's primary <a href="https://www.open.mp/docs/scripting/resources/vehiclecolorid">colour
 * ID</a></param>
 * <param name="color2">The new vehicle's secondary <a href="https://www.open.mp/docs/scripting/resources/vehiclecolorid">colour
 * ID</a></param>
 * <seealso name="ChangeVehiclePaintjob" />
 * <seealso name="OnVehicleRespray" />
 * <remarks>Some vehicles have only a primary colour and some can not have the colour changed at all.
 *  A few (cement, squallo) have 4 colours, of which 2 can not currently be changed.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  The vehicle's colour was successfully changed.<br
 * />
 *   <b><c>0</c></b>: The function failed to execute.  The vehicle does not exist.
 * </returns>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `ChangeVehicleColours`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:ChangeVehicleColor(vehicleid, color1, color2);

/**
 * <library>omp_vehicle</library>
 * <summary>Change a vehicle's primary and secondary colours.</summary>
 * <param name="vehicleid">The ID of the vehicle to change the colours of</param>
 * <param name="colour1">The new vehicle's primary <a href="https://www.open.mp/docs/scripting/resources/vehiclecolorid">colour
 * ID</a></param>
 * <param name="colour2">The new vehicle's secondary <a href="https://www.open.mp/docs/scripting/resources/vehiclecolorid">colour
 * ID</a></param>
 * <seealso name="ChangeVehiclePaintjob" />
 * <seealso name="OnVehicleRespray" />
 * <remarks>Some vehicles have only a primary colour and some can not have the colour changed at all.
 *  A few (cement, squallo) have 4 colours, of which 2 can not currently be changed.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  The vehicle's colour was successfully changed.<br
 * />
 *   <b><c>0</c></b>: The function failed to execute.  The vehicle does not exist.
 * </returns>
 */
native bool:ChangeVehicleColours(vehicleid, colour1, colour2) = ChangeVehicleColor;

/**
 * <library>omp_vehicle</library>
 * <summary>Change a vehicle's paintjob (for plain colours see <a href="#ChangeVehicleColor">ChangeVehicleColor</a>).</summary>
 * <param name="vehicleid">The ID of the vehicle to change the paintjob of</param>
 * <param name="paintjob">The ID of the Paintjob to apply.  Use <b><c>3</c></b> to remove a paintjob</param>
 * <seealso name="ChangeVehicleColours" />
 * <seealso name="OnVehiclePaintjob" />
 * <remarks>
 *   <b>Known Bugs:</b><br />
 *   This function calls <a href="#OnVehicleRespray">OnVehicleRespray</a>.<br />
 *   Vehicles change their colour to white anymore when a paintjob is removed.
 * </remarks>
 * <returns>This function always returns <b><c>1</c></b> (success), even if the vehicle passed is not
 * created.</returns>
 */
native bool:ChangeVehiclePaintjob(vehicleid, paintjob);

/**
 * <library>omp_vehicle</library>
 * <summary>Set a vehicle's health.  When a vehicle's health decreases the engine will produce smoke,
 * and finally fire when it decreases to less than 250 (25%).</summary>
 * <param name="vehicleid">The ID of the vehicle to set the health of</param>
 * <param name="health">The health, given as a float value</param>
 * <seealso name="GetVehicleHealth" />
 * <seealso name="RepairVehicle" />
 * <seealso name="SetPlayerHealth" />
 * <seealso name="OnVehicleDeath" />
 * <remarks>Full vehicle health is <b><c>1000</c></b>, however higher values are possible and increase
 * the health of the vehicle.</remarks>
 * <remarks>
 *   <b>Health:</b><br />
 *   <ul>
 *     <li>&gt; 650 - undamaged</li>
 *     <li>650-550 - white Smoke</li>
 *     <li>550-390 - grey Smoke</li>
 *     <li>390-250 - black Smoke</li>
 *     <li>&lt; 250 - on fire (will explode seconds later)</li>
 *   </ul>
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the vehicle does not exist.
 * </returns>
 */
native bool:SetVehicleHealth(vehicleid, Float:health);

/**
 * <library>omp_vehicle</library>
 * <summary>Get the health of a vehicle.</summary>
 * <param name="vehicleid">The ID of the vehicle to get the health of</param>
 * <param name="health">A float variable in which to store the vehicle's health, passed by reference</param>
 * <seealso name="SetVehicleHealth" />
 * <seealso name="GetPlayerHealth" />
 * <seealso name="GetPlayerArmour" />
 * <remarks>Full vehicle health is <b><c>1000</c></b>, however higher values are possible and increase
 * the health of the vehicle.</remarks>
 * <remarks>
 *   <b>Health:</b><br />
 *   <ul>
 *     <li>&gt; 650 - undamaged</li>
 *     <li>650-550 - white Smoke</li>
 *     <li>550-390 - grey Smoke</li>
 *     <li>390-250 - black Smoke</li>
 *     <li>&lt; 250 - on fire (will explode seconds later)</li>
 *   </ul>
 * </remarks>
 * <returns>
 *   <b><c>1</c></b> - success.<br />
 *   <b><c>0</c></b> - failure (invalid vehicle ID).<br />
 * </returns>
 */
native bool:GetVehicleHealth(vehicleid, &Float:health);

/**
 * <library>omp_vehicle</library>
 * <summary>Attach a vehicle to another vehicle as a trailer.</summary>
 * <param name="trailerid">The ID of the vehicle that will be pulled</param>
 * <param name="vehicleid">The ID of the vehicle that will pull the trailer</param>
 * <seealso name="DetachTrailerFromVehicle" />
 * <seealso name="IsTrailerAttachedToVehicle" />
 * <seealso name="GetVehicleTrailer" />
 * <remarks>This will only work if both vehicles are streamed in for a player (check
 * <a href="#IsVehicleStreamedIn">IsVehicleStreamedIn</a>).</remarks>
 * <returns>This function always returns <b><c>1</c></b>, even if neither of the vehicle IDs passed
 * are valid.</returns>
 */
native bool:AttachTrailerToVehicle(trailerid, vehicleid);

/**
 * <library>omp_vehicle</library>
 * <summary>Detach the connection between a vehicle and its trailer, if any.</summary>
 * <param name="vehicleid">ID of the pulling vehicle</param>
 * <seealso name="AttachTrailerToVehicle" />
 * <seealso name="IsTrailerAttachedToVehicle" />
 * <seealso name="GetVehicleTrailer" />
 */
native bool:DetachTrailerFromVehicle(vehicleid);

/**
 * <library>omp_vehicle</library>
 * <summary>Checks if a vehicle has a trailer attached to it.  Use <a href="#GetVehicleTrailer">GetVehicleTrailer</a>
 * to get the vehicle ID of the trailer (if any).</summary>
 * <param name="vehicleid">The ID of the vehicle to check for trailers</param>
 * <seealso name="GetVehicleTrailer" />
 * <seealso name="AttachTrailerToVehicle" />
 * <seealso name="DetachTrailerFromVehicle" />
 * <returns><b><c>1</c></b> if the vehicle has a trailer attached, <b><c>0</c></b> if not.</returns>
 */
native bool:IsTrailerAttachedToVehicle(vehicleid);

/**
 * <library>omp_vehicle</library>
 * <summary>Get the ID of the trailer attached to a vehicle.</summary>
 * <param name="vehicleid">The ID of the vehicle to get the trailer of</param>
 * <seealso name="AttachTrailerToVehicle" />
 * <seealso name="DetachTrailerFromVehicle" />
 * <seealso name="IsTrailerAttachedToVehicle" />
 * <returns>The vehicle ID of the trailer or <b><c>0</c></b> if no trailer is attached.</returns>
 */
native GetVehicleTrailer(vehicleid);

/**
 * <library>omp_vehicle</library>
 * <summary>Set a vehicle numberPlate.</summary>
 * <param name="vehicleid">The ID of the vehicle to set the number plate of</param>
 * <param name="numberPlate">The text that should be displayed on the number plate</param>
 * <seealso name="SetVehicleToRespawn" />
 * <seealso name="ChangeVehicleColours" />
 * <seealso name="ChangeVehiclePaintjob" />
 * <remarks>You can use colour embedding on the number plate text.</remarks>
 * <remarks>
 *   This function has no internal error checking.  Do not assign custom number plates to vehicles without
 * plates (boats, planes, etc) as this will result in some unneeded processing time on the client.<br
 * />
 *   The vehicle must be re-spawned or re-streamed for the changes to take effect.<br />
 *   There's a limit of 32 characters on each number plate (including embedded colours).<br />
 *   The text length that can be seen on the number plate is around 9 to 10 characters, more characters
 * will cause the text to split.<br />
 *   Some vehicle models has a backward number plate, e.g.  Boxville (498) (as an alternative to this
 * vehicle you can use vehicle model ID 609, which is a duplicated Boxville (aka Boxburg), but with
 * a regular number plate).<br />
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The vehicle does not exist.<br />
 * </returns>
 */
native bool:SetVehicleNumberPlate(vehicleid, const numberPlate[]);

/**
 * <library>omp_vehicle</library>
 * <summary>Gets the <a href="https://www.open.mp/docs/scripting/resources/vehicleid">model ID</a> of a vehicle.</summary>
 * <param name="vehicleid">The ID of the vehicle to get the model of</param>
 * <seealso name="GetPlayerVehicleid" />
 * <seealso name="GetVehiclePos" />
 * <seealso name="GetVehicleZAngle" />
 * <seealso name="GetPlayerVehicleSeat" />
 * <returns>The vehicle's <a href="https://www.open.mp/docs/scripting/resources/vehicleid">model ID</a>, or <b><c>0</c></b>
 * if the vehicle doesn't exist.</returns>
 */
native GetVehicleModel(vehicleid);

/**
 * <library>omp_vehicle</library>
 * <summary>Retrieves the installed component ID (modshop mod(ification)) on a vehicle in a specific
 * slot.</summary>
 * <param name="vehicleid">The ID of the vehicle to check for the component</param>
 * <param name="slot">The component slot to check for components (see below)</param>
 * <seealso name="AddVehicleComponent" />
 * <seealso name="GetVehicleComponentType" />
 * <seealso name="OnVehicleMod" />
 * <seealso name="OnEnterExitModShop" />
 * <remarks>
 *   <b>Slots:</b><br />
 *   <c>
 *     CARMODTYPE_SPOILER
 *     CARMODTYPE_HOOD
 *     CARMODTYPE_ROOF
 *     CARMODTYPE_SIDESKIRT
 *     CARMODTYPE_LAMPS
 *     CARMODTYPE_NITRO
 *     CARMODTYPE_EXHAUST
 *     CARMODTYPE_WHEELS
 *     CARMODTYPE_STEREO
 *     CARMODTYPE_HYDRAULICS
 *     CARMODTYPE_FRONT_BUMPER
 *     CARMODTYPE_REAR_BUMPER
 *     CARMODTYPE_VENT_RIGHT
 *     CARMODTYPE_VENT_LEFT
 *   </c>
 * </remarks>
 * <remarks>
 *   <b>Known Bugs:</b><br />
 *   <ul>
 *     <li>Doesn't work for <b><c>CARMODTYPE_STEREO</c></b>.</li>
 *     <li>Both front bull bars and front bumper components are saved in the <b><c>CARMODTYPE_FRONT_BUMPER</c></b>
 * slot.  If a vehicle has both of them installed, this function will only return the one which was
 * installed last.</li>
 *     <li>Both rear bull bars and rear bumper components are saved in the <b><c>CARMODTYPE_REAR_BUMPER</c></b>
 * slot.  If a vehicle has both of them installed, this function will only return the one which was
 * installed last.</li>
 *     <li>Both left side skirt and right side skirt are saved in the <b><c>CARMODTYPE_SIDESKIRT</c></b>
 * slot.  If a vehicle has both of them installed, this function will only return the one which was
 * installed last. </li>
 *   </ul>
 * </remarks>
 * <returns>The ID of the component installed in the specified slot.  Returns <b><c>0</c></b> if no
 * component in specified vehicle's specified slot, or if vehicle doesn't exist.</returns>
 */
native GetVehicleComponentInSlot(vehicleid, CARMODTYPE:slot);

/**
 * <library>omp_vehicle</library>
 * <summary>Find out what type of component a certain ID is.</summary>
 * <param name="component">The component ID to check</param>
 * <seealso name="AddVehicleComponent" />
 * <seealso name="RemoveVehicleComponent" />
 * <seealso name="GetVehicleComponentInSlot" />
 * <seealso name="OnVehicleMod" />
 * <seealso name="OnEnterExitModShop" />
 * <returns>The component slot ID of the specified component or <b><c>-1</c></b> if the component is
 * invalid.</returns>
 */
native CARMODTYPE:GetVehicleComponentType(component);

/**
 * <library>omp_vehicle</library>
 * <summary>
 * Get random colour indexes that are valid for the given vehicle model.
 * </summary>
 */
native bool:GetRandomCarColPair(modelid, &colour1, &colour2, &colour3 = 0, &colour4 = 0);

/**
 * <library>omp_vehicle</library>
 * <summary>
 * Get random colour indexes that are valid for the given vehicle model.
 * </summary>
 */
native bool:GetRandomVehicleColourPair(modelid, &colour1, &colour2, &colour3 = 0, &colour4 = 0) = GetRandomCarColPair;

/**
 * <library>omp_vehicle</library>
 * <summary>
 * Get random colour indexes that are valid for the given vehicle model.
 * </summary>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `GetRandomVehicleColourPair`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:GetRandomVehicleColorPair(modelid, &color1, &color2, &color3 = 0, &color4 = 0) = GetRandomCarColPair;

/**
 * <library>omp_vehicle</library>
 * <summary>
 * Convert a car colour index to a HEX colour (RGBA).
 * </summary>
 */
#pragma deprecated Use `VehicleColourIndexToColour`
native CarColIndexToColour(index, alpha = 0xFF);

/**
 * <library>omp_vehicle</library>
 * <summary>
 * Convert a car colour index to a HEX colour (RGBA).
 * </summary>
 */
native VehicleColourIndexToColour(index, alpha = 0xFF) = CarColIndexToColour;

/**
 * <library>omp_vehicle</library>
 * <summary>Fully repairs a vehicle, including visual damage (bumps, dents, scratches, popped tires
 * etc.).</summary>
 * <param name="vehicleid">The ID of the vehicle to repair</param>
 * <seealso name="SetVehicleHealth" />
 * <seealso name="GetVehicleHealth" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the vehicle specified does not exist.
 * </returns>
 */
native bool:RepairVehicle(vehicleid);

/**
 * <library>omp_vehicle</library>
 * <summary>Get the velocity of a vehicle on the x, y and z axes.</summary>
 * <param name="vehicleid">The ID of the vehicle to get the velocity of</param>
 * <param name="x">A float variable in to which to store the vehicle's x velocity, passed by reference</param>
 * <param name="y">A float variable in to which to store the vehicle's y velocity, passed by reference</param>
 * <param name="z">A float variable in to which to store the vehicle's z velocity, passed by reference</param>
 * <seealso name="GetPlayerVelocity" />
 * <seealso name="SetVehicleVelocity" />
 * <seealso name="SetPlayerVelocity" />
 * <remarks>Multiply vector with <b><c>250.66667</c></b> for kmph or <b><c>199.416667</c></b> for mph
 * or something...</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the vehicle specified does not exist.<br
 * />
 * </returns>
 */
native bool:GetVehicleVelocity(vehicleid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_vehicle</library>
 * <summary>Sets the x, y and z velocity of a vehicle.</summary>
 * <param name="vehicleid">The ID of the vehicle to set the velocity of</param>
 * <param name="x">The velocity in the x direction</param>
 * <param name="y">The velocity in the y direction </param>
 * <param name="z">The velocity in the z direction</param>
 * <remarks>This function has no affect on un-occupied vehicles and does not affect trains.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The vehicle does not exist.
 * </returns>
 */
native bool:SetVehicleVelocity(vehicleid, Float:x, Float:y, Float:z);

/**
 * <library>omp_vehicle</library>
 * <summary>Sets the angular x, y and z velocity of a vehicle.</summary>
 * <param name="vehicleid">The ID of the vehicle to set the velocity of</param>
 * <param name="x">The amount of velocity in the angular x direction</param>
 * <param name="y">The amount of velocity in the angular y direction </param>
 * <param name="z">The amount of velocity in the angular z direction</param>
 * <seealso name="SetVehicleVelocity" />
 * <seealso name="GetVehicleVelocity" />
 * <remarks>This function has no effect on un-occupied vehicles and does not effect trains.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The vehicle does not exist.
 * </returns>
 */
native bool:SetVehicleAngularVelocity(vehicleid, Float:x, Float:y, Float:z);

/**
 * <library>omp_vehicle</library>
 * <summary>Retrieve the damage statuses of a vehicle.</summary>
 * <param name="vehicleid">The ID of the vehicle to get the damage statuses of</param>
 * <param name="panels">A variable to store the panel damage data in, passed by reference</param>
 * <param name="doors">A variable to store the door damage data in, passed by reference</param>
 * <param name="lights">A variable to store the light damage data in, passed by reference</param>
 * <param name="tires">A variable to store the tyre damage data in, passed by reference</param>
 * <seealso name="UpdateVehicleDamageStatus" />
 * <seealso name="SetVehicleHealth" />
 * <seealso name="GetVehicleHealth" />
 * <seealso name="RepairVehicle" />
 * <seealso name="OnVehicleDamageStatusUpdate" />
 * <remarks>
 *   <b>Door states:</b><br />
 *   <ul>
 *     <li><b><c>0x000000FF</c></b> - hood</li>
 *     <li><b><c>0x0000FF00</c></b> - trunk</li>
 *     <li><b><c>0x00FF0000</c></b> - drivers door</li>
 *     <li><b><c>0xFF000000</c></b> - co-drivers door</li>
 *     <li>byte meaning:</li>
 *     <li><b><c>0x1</c></b> - is opened</li>
 *     <li><b><c>0x2</c></b> - is damaged</li>
 *     <li><b><c>0x4</c></b> - is removed</li>
 *     <li>other bytes are unused</li>
 *   </ul>
 * </remarks>
 * <remarks>
 *   <b>Light states:</b><br />
 *   <ul>
 *     <li><b><c>0x01</c></b> - front left broken</li>
 *     <li><b><c>0x04</c></b> - front right broken</li>
 *     <li><b><c>0x40</c></b> - back both broken</li>
 *   </ul>
 * </remarks>
 * <remarks>
 *   <b>Tire states:</b><br />
 *   <ul>
 *     <li><b><c>0x1</c></b> - back right popped</li>
 *     <li><b><c>0x2</c></b> - front right popped</li>
 *     <li><b><c>0x4</c></b> - back left popped</li>
 *     <li><b><c>0x8</c></b> - front left popped</li>
 *     <li>only check the right states for bikes</li>
 *   </ul>
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the vehicle specified does not exist.
 * </returns>
 */
native bool:GetVehicleDamageStatus(vehicleid, &VEHICLE_PANEL_STATUS:panels, &VEHICLE_DOOR_STATUS:doors, &VEHICLE_LIGHT_STATUS:lights, &VEHICLE_TYRE_STATUS:tyres);

/**
 * <library>omp_vehicle</library>
 * <summary>Sets the various visual damage statuses of a vehicle, such as popped tires, broken lights
 * and damaged panels.</summary>
 * <param name="vehicleid">The ID of the vehicle to set the damage of</param>
 * <param name="panels">A set of bits containing the panel damage status</param>
 * <param name="doors">A set of bits containing the door damage status</param>
 * <param name="lights">A set of bits containing the light damage status</param>
 * <param name="tires">A set of bits containing the tyre damage status</param>
 * <seealso name="SetVehicleHealth" />
 * <seealso name="GetVehicleHealth" />
 * <seealso name="RepairVehicle" />
 * <seealso name="GetVehicleDamageStatus" />
 * <seealso name="OnVehicleDamageStatusUpdate" />
 * <remarks>
 *   <b>Door states:</b><br />
 *   <ul>
 *     <li><b><c>0x000000FF</c></b> - hood</li>
 *     <li><b><c>0x0000FF00</c></b> - trunk</li>
 *     <li><b><c>0x00FF0000</c></b> - drivers door</li>
 *     <li><b><c>0xFF000000</c></b> - co-drivers door</li>
 *     <li>byte meaning:</li>
 *     <li><b><c>0x1</c></b> - is opened</li>
 *     <li><b><c>0x2</c></b> - is damaged</li>
 *     <li><b><c>0x4</c></b> - is removed</li>
 *     <li>other bytes are unused</li>
 *   </ul>
 * </remarks>
 * <remarks>
 *   <b>Light states:</b><br />
 *   <ul>
 *     <li><b><c>0x01</c></b> - front left broken</li>
 *     <li><b><c>0x04</c></b> - front right broken</li>
 *     <li><b><c>0x40</c></b> - back both broken</li>
 *   </ul>
 * </remarks>
 * <remarks>
 *   <b>Tire states:</b><br />
 *   <ul>
 *     <li><b><c>0x1</c></b> - back right popped</li>
 *     <li><b><c>0x2</c></b> - front right popped</li>
 *     <li><b><c>0x4</c></b> - back left popped</li>
 *     <li><b><c>0x8</c></b> - front left popped</li>
 *     <li>only check the right states for bikes</li>
 *   </ul>
 * </remarks>
 */
native bool:UpdateVehicleDamageStatus(vehicleid, VEHICLE_PANEL_STATUS:panels, VEHICLE_DOOR_STATUS:doors, VEHICLE_LIGHT_STATUS:lights, VEHICLE_TYRE_STATUS:tires);

/**
 * <library>omp_vehicle</library>
 * <summary>Retrieve information about a specific vehicle model such as the size or position of seats.</summary>
 * <param name="vehiclemodel">The vehicle <a href="https://www.open.mp/docs/scripting/resources/vehicleid">model</a>
 * to get info of</param>
 * <param name="infotype">The type of information to retrieve</param>
 * <param name="x">A float to store the x value</param>
 * <param name="y">A float to store the y value</param>
 * <param name="z">A float to store the z value</param>
 * <seealso name="GetVehicleModel" />
 * <remarks>
 *   <b>Information types:</b><br />
 *   <ul>
 *     <li><b><c>VEHICLE_MODEL_INFO_SIZE</c></b> - vehicle size</li>
 *     <li><b><c>VEHICLE_MODEL_INFO_FRONTSEAT</c></b> - position of the front seat</li>
 *     <li><b><c>VEHICLE_MODEL_INFO_REARSEAT</c></b> - position of the rear seat</li>
 *     <li><b><c>VEHICLE_MODEL_INFO_PETROLCAP</c></b> - position of the fuel cap</li>
 *     <li><b><c>VEHICLE_MODEL_INFO_WHEELSFRONT</c></b> - position of the front wheels</li>
 *     <li><b><c>VEHICLE_MODEL_INFO_WHEELSREAR</c></b> - position of the rear wheels</li>
 *     <li><b><c>VEHICLE_MODEL_INFO_WHEELSMID</c></b> - position of the middle wheels (applies to vehicles
 * with 3 axes)</li>
 *     <li><b><c>VEHICLE_MODEL_INFO_FRONT_BUMPER_Z</c></b> - height of the front bumper</li>
 *     <li><b><c>VEHICLE_MODEL_INFO_REAR_BUMPER_Z </c></b> - height of the rear bumper</li>
 *   </ul>
 * </remarks>
 */
native bool:GetVehicleModelInfo(vehiclemodel, VEHICLE_MODEL_INFO:infotype, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_vehicle</library>
 * <summary>Sets the 'virtual world' of a vehicle.  Players will only be able to see vehicles in their
 * own virtual world.</summary>
 * <param name="vehicleid">The ID of vehicle to set the virtual world of</param>
 * <param name="virtualWorld">The ID of the virtual world to put the vehicle in</param>
 * <seealso name="GetVehicleVirtualWorld" />
 * <seealso name="SetPlayerVirtualWorld" />
 */
native bool:SetVehicleVirtualWorld(vehicleid, virtualWorld);

/**
 * <library>omp_vehicle</library>
 * <summary>Get the virtual world of a vehicle.</summary>
 * <param name="vehicleid">The ID of the vehicle to get the virtual world of</param>
 * <seealso name="SetVehicleVirtualWorld" />
 * <seealso name="GetPlayerVirtualWorld" />
 * <returns>The virtual world that the vehicle is in.</returns>
 */
native GetVehicleVirtualWorld(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native bool:GetVehicleSirenState(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native LANDING_GEAR_STATE:GetVehicleLandingGearState(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native GetVehicleHydraReactorAngle(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native Float:GetVehicleTrainSpeed(vehicleid);

/**
 * <library>omp_vehicle</library>
 * <summary>Check if a vehicle ID is valid.</summary>
 * <param name="vehicleid">The ID of the vehicle to check</param>
 * <seealso name="CreateVehicle" />
 * <seealso name="DestroyVehicle" />
 * <returns>true or false.</returns>
 */
native bool:IsValidVehicle(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native bool:GetVehicleSpawnInfo(vehicleid, &Float:spawnX, &Float:spawnY, &Float:spawnZ, &Float:angle, &colour1 = 0, &colour2 = 0);

/**
 * <library>omp_vehicle</library>
 */
native bool:SetVehicleSpawnInfo(vehicleid, modelid, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, colour1, colour2, respawnDelay = -2, interior = -2);

/**
 * <library>omp_vehicle</library>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `GetVehicleColours`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:GetVehicleColor(vehicleid, &color1, &color2);

/**
 * <library>omp_vehicle</library>
 */
native bool:GetVehicleColours(vehicleid, &colour1, &colour2) = GetVehicleColor;

/**
 * <library>omp_vehicle</library>
 */
native GetVehiclePaintjob(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native GetVehicleInterior(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native bool:GetVehicleNumberPlate(vehicleid, plate[], len = sizeof (plate));

/**
 * <library>omp_vehicle</library>
 */
native bool:SetVehicleRespawnDelay(vehicleid, respawnDelay);

/**
 * <library>omp_vehicle</library>
 */
native GetVehicleRespawnDelay(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native GetVehicleOccupiedTick(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native GetVehicleRespawnTick(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native GetVehicleLastDriver(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native GetVehicleDriver(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native bool:IsPlayerInModShop(playerid);

/**
 * <library>omp_vehicle</library>
 */
native bool:GetPlayerSirenState(playerid);

/**
 * <library>omp_vehicle</library>
 */
native LANDING_GEAR_STATE:GetPlayerLandingGearState(playerid);

/**
 * <library>omp_vehicle</library>
 */
native GetPlayerHydraReactorAngle(playerid);

/**
 * <library>omp_vehicle</library>
 */
native Float:GetPlayerTrainSpeed(playerid);

/**
 * <library>omp_vehicle</library>
 */
native GetVehicleCab(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native bool:HasVehicleBeenOccupied(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native bool:IsVehicleOccupied(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native bool:IsVehicleDead(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native bool:ToggleVehicleSirenEnabled(vehicleid, bool:enabled);

/**
 * <library>omp_vehicle</library>
 * <summary>Turn the siren for a vehicle on or off.</summary>
 */
native bool:IsVehicleSirenEnabled(vehicleid);

/**
 * <library>omp_vehicle</library>
 */
native bool:GetVehicleMatrix(vehicleid, &Float:rightX, &Float:rightY, &Float:rightZ, &Float:upX, &Float:upY, &Float:upZ, &Float:atX, &Float:atY, &Float:atZ);

/**
 * <library>omp_vehicle</library>
 */
native GetVehicleModelCount(modelid);

/**
 * <library>omp_vehicle</library>
 */
native GetVehicleModelsUsed();

/**
 * <library>omp_vehicle</library>
 * <summary>Enable friendly fire for team vehicles.  Players will be unable to damage teammates' vehicles
 * (<a href="#SetPlayerTeam">SetPlayerTeam</a> must be used!).</summary>
 * <seealso name="SetPlayerTeam" />
 */
native void:EnableVehicleFriendlyFire();

/**
 * <library>omp_vehicle</library>
 * <summary>Get an array variable of the IDs of the created vehicles on the server.</summary>
 * <param name="vehicles">An array into which to store the vehicle IDs, passed by reference.</param>
 * <param name="size">The size of the array.</param>
 * <seealso name="GetPlayers" />
 * <seealso name="GetActors" />
 * <returns>The number of vehicles stored in the array.</returns>
 */
native GetVehicles(vehicles[], size = sizeof (vehicles));

/**
 * <library>omp_vehicle</library>
 * <summary>Retrieves the ID of the player who is sitting in the given seat.</summary>
 * <param name="vehicleid">The ID of the vehicle.</param>
 * <param name="seatid">The ID of the seat in which you are looking for an occupant.</param>
 * <seealso name="CountVehicleOccupants" />
 * <returns>
 *   <b><c>occupant's ID</c></b>: There is a player in that seat.<br />
 *   <b><c>INVALID_PLAYER_ID</c></b>: The seat is empty or the vehicle is not created.
 * </returns>
 */
native GetVehicleOccupant(vehicleid, seatid);

/**
 * <library>omp_vehicle</library>
 * <summary>Returns the number of occupants in the given vehicle.</summary>
 * <param name="modelid">The ID of the vehicle.</param>
 * <seealso name="GetVehicleOccupant" />
 * <returns>
 *   <b><c>occupants number</c></b>: The number of occupants as an intiger.<br />
 * </returns>
 */
native CountVehicleOccupants(vehicleid);

/*
native # Deprecated();
native           Deprecated(
native      ====================(
native
*/

/**
 * <library>omp_vehicle</library>
 * <remarks>As in "one who tows", not "tall building".</remarks>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `GetVehicleCab`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native GetVehicleTower(vehicleid);

/*
                                                                                                  
      ,ad8888ba,               88  88  88                                   88                    
     d8"'    `"8b              88  88  88                                   88                    
    d8'                        88  88  88                                   88                    
    88             ,adPPYYba,  88  88  88,dPPYba,   ,adPPYYba,   ,adPPYba,  88   ,d8   ,adPPYba,  
    88             ""     `Y8  88  88  88P'    "8a  ""     `Y8  a8"     ""  88 ,a8"    I8[    ""  
    Y8,            ,adPPPPP88  88  88  88       d8  ,adPPPPP88  8b          8888[       `"Y8ba,   
     Y8a.    .a8P  88,    ,88  88  88  88b,   ,a8"  88,    ,88  "8a,   ,aa  88`"Yba,   aa    ]8I  
      `"Y8888Y"'   `"8bbdP"Y8  88  88  8Y"Ybbd8"'   `"8bbdP"Y8   `"Ybbd8"'  88   `Y8a  `"YbbdP"'  
                                                                                                  
                                                                                                  

*/

/**
 * <summary>This callback is called when a player sent a trailer update.</summary>
 * <param name="playerid">The ID of the player who sent a trailer update</param>
 * <param name="vehicleid">The Trailer being updated</param>
 * <seealso name="OnUnoccupiedVehicleUpdate" />
 * <seealso name="GetVehicleTrailer" />
 * <seealso name="IsTrailerAttachedToVehicle" />
 * <seealso name="AttachTrailerToVehicle" />
 * <seealso name="DetachTrailerFromVehicle" />
 * <remarks>This callback is called very frequently per second per trailer.  You should refrain from
 * implementing intensive calculations or intensive file writing/reading operations in this callback.
 * </remarks>
 * <returns>
 *   <b><c>0</c></b> - Cancels any trailer updates from being sent to other players.  Update is still
 * sent to the updating player.<br />
 *   <b><c>1</c></b> - Processes the trailer update as normal and synchronizes it between all players.<br
 * />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnTrailerUpdate(playerid, vehicleid);

/**
 * <summary>This callback is called when a vehicle's siren is toggled.</summary>
 * <param name="playerid">The ID of the player that toggled the siren (driver)</param>
 * <param name="vehicleid">The ID of the vehicle of which the siren was toggled for</param>
 * <param name="newstate"><b><c>0</c></b> if siren was turned off, <b><c>1</c></b> if siren was turned
 * on</param>
 * <seealso name="GetVehicleParamsSirenState" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <remarks>This callback is only called when a vehicle's siren is toggled on or off, NOT when the alternate
 * siren is in use (holding horn).</remarks>
 * <returns>
 *   <b><c>1</c></b> - Will prevent gamemode from receiving this callback.<br />
 *   <b><c>0</c></b> - Indicates that this callback will be passed to the gamemode.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnVehicleSirenStateChange(playerid, vehicleid, newstate);

/**
 * <summary>Called when a vehicle is streamed to a player's client.</summary>
 * <param name="vehicleid">The ID of the vehicle that streamed in for the player</param>
 * <param name="forplayerid">The ID of the player who the vehicle streamed in for</param>
 * <seealso name="OnVehicleStreamOut" />
 * <seealso name="OnPlayerStreamIn" />
 * <seealso name="OnPlayerStreamOut" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnVehicleStreamIn(vehicleid, forplayerid);

/**
 * <summary>This callback is called when a vehicle is streamed out for a player's client (it's so far
 * away that they can't see it).</summary>
 * <param name="vehicleid">The ID of the vehicle that streamed out</param>
 * <param name="forplayerid">The ID of the player who is no longer streaming the vehicle</param>
 * <seealso name="OnVehicleStreamIn" />
 * <seealso name="OnPlayerStreamIn" />
 * <seealso name="OnPlayerStreamOut" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnVehicleStreamOut(vehicleid, forplayerid);

/**
 * <summary>This callback is called when a player <b><c>starts</c></b> to enter a vehicle, meaning the
 * player is not in vehicle yet at the time this callback is called.</summary>
 * <param name="playerid">ID of the player who attempts to enter a vehicle</param>
 * <param name="vehicleid">ID of the vehicle the player is attempting to enter</param>
 * <param name="ispassenger"><b><c>0</c></b> if entering as driver. <b><c>1</c></b> if entering as passenger</param>
 * <seealso name="OnPlayerExitVehicle" />
 * <seealso name="OnPlayerStateChange" />
 * <seealso name="PutPlayerInVehicle" />
 * <seealso name="GetPlayerVehicleSeat" />
 * <remarks>This callback is called when a player <b>BEGINS</b> to enter a vehicle, not when they HAVE
 * entered it.  See <a href="#OnPlayerStateChange">OnPlayerStateChange</a>. </remarks>
 * <remarks>This callback is still called if the player is denied entry to the vehicle (e.g.  it is
 * locked or full). </remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);

/**
 * <summary>This callback is called when a player <b>starts</b> to exit a vehicle.</summary>
 * <param name="playerid">The ID of the player that is exiting a vehicle</param>
 * <param name="vehicleid">The ID of the vehicle the player is exiting</param>
 * <seealso name="OnPlayerEnterVehicle" />
 * <seealso name="OnPlayerStateChange" />
 * <seealso name="RemovePlayerFromVehicle" />
 * <seealso name="GetPlayerVehicleSeat" />
 * <remarks>Not called if the player falls off a bike or is removed from a vehicle by other means such
 * as using <a href="#SetPlayerPos">SetPlayerPos</a>.</remarks>
 * <remarks>You must use <a href="#OnPlayerStateChange">OnPlayerStateChange</a> and check if their old
 * state is <b><c>PLAYER_STATE_DRIVER</c></b> or <b><c>PLAYER_STATE_PASSENGER</c></b> and their new
 * state is <b><c>PLAYER_STATE_ONFOOT</c></b>.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerExitVehicle(playerid, vehicleid);

/**
 * <summary>This callback is called when a vehicle <b>re</b>spawns.</summary>
 * <param name="vehicleid">The ID of the vehicle that spawned</param>
 * <seealso name="OnVehicleDeath" />
 * <seealso name="OnPlayerSpawn" />
 * <seealso name="SetVehicleToRespawn" />
 * <seealso name="CreateVehicle" />
 * <returns>
 *   <b><c>0</c></b> - Will prevent other filterscripts from receiving this callback.<br />
 *   <b><c>1</c></b> - Indicates that this callback will be passed to the next filterscript.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnVehicleSpawn(vehicleid);

/**
 * <summary>This callback is called when a vehicle is destroyed - either by exploding or becoming submerged
 * in water.</summary>
 * <param name="vehicleid">The ID of the vehicle that was destroyed</param>
 * <param name="killerid">The ID of the player that reported (synced) the vehicle's destruction (name
 * is misleading).  Generally the driver or a passenger (if any) or the closest player</param>
 * <seealso name="OnVehicleSpawn" />
 * <seealso name="SetVehicleHealth" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <remarks>This callback will also be called when a vehicle enters water, but the vehicle can be saved
 * from destruction by teleportation or driving out (if only partially submerged).  The callback won't
 * be called a second time, and the vehicle may disappear when the driver exits, or after a short time.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnVehicleDeath(vehicleid, killerid);

/**
 * <summary>This callback is called when a vehicle is modded.</summary>
 * <param name="playerid">The ID of the driver of the vehicle</param>
 * <param name="vehicleid">The ID of the vehicle which is modded</param>
 * <param name="componentid">The ID of the component which was added to the vehicle</param>
 * <seealso name="AddVehicleComponent" />
 * <seealso name="OnEnterExitModShop" />
 * <seealso name="OnVehiclePaintjob" />
 * <seealso name="OnVehicleRespray" />
 * <remarks>This callback is NOT called by <a href="#AddVehicleComponent">AddVehicleComponent</a>.</remarks>
 * <returns>
 *   Return <b><c>0</c></b> to desync the mod (or an invalid mod) from propagating and / or crashing
 * players.<br />
 *   It is always called first in gamemode so returning <b><c>0</c></b> there also blocks other filterscripts
 * from seeing it.
 * </returns>
 */
forward OnVehicleMod(playerid, vehicleid, componentid);

/**
 * <summary>This callback is called when a player enters or exits a mod shop.</summary>
 * <param name="playerid">The ID of the player that entered or exited the modshop</param>
 * <param name="enterexit"><b><c>1</c></b> if the player entered or <b><c>0</c></b> if they exited</param>
 * <param name="interiorid">The interior ID of the modshop that the player is entering (or 0 if exiting)</param>
 * <seealso name="OnVehicleMod" />
 * <seealso name="OnVehicleRespray" />
 * <seealso name="OnVehiclePaintjob" />
 * <seealso name="AddVehicleComponent" />
 * <remarks>Players collide when they get into the same mod shop.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnEnterExitModShop(playerid, enterexit, interiorid);

/**
 * <summary>Called when a player previews a vehicle paintjob inside a mod shop.  Watch out, this callback
 * is not called when the player buys the paintjob.</summary>
 * <param name="playerid">The ID of the player that changed the paintjob of their vehicle</param>
 * <param name="vehicleid">The ID of the vehicle that had its paintjob changed</param>
 * <param name="paintjobid">The ID of the new paintjob</param>
 * <seealso name="ChangeVehiclePaintjob" />
 * <seealso name="ChangeVehicleColours" />
 * <seealso name="OnVehicleRespray" />
 * <seealso name="OnVehicleMod" />
 * <remarks>This callback is not called by <a href="#ChangeVehiclePaintjob">ChangeVehiclePaintjob</a>.</remarks>
 * <returns>
 *   This callback does not handle returns.  Returning <b><c>0</c></b> won't deny the paintjob change.<br
 * />
 *   It is always called first in gamemode so returning <b><c>0</c></b> there blocks other filterscripts
 * from seeing it.
 * </returns>
 */
forward OnVehiclePaintjob(playerid, vehicleid, paintjobid);

/**
 * <summary>This callback is called when a player exits a mod shop, even if the colours weren't changed.
 *  Watch out, the name is ambiguous, Pay 'n' Spray shops don't call this callback.</summary>
 * <param name="playerid">The ID of the player that is driving the vehicle</param>
 * <param name="vehicleid">The ID of the vehicle that was resprayed</param>
 * <param name="color1">The colour that the vehicle's primary colour was changed to</param>
 * <param name="color2">The colour that the vehicle's secondary colour was changed to</param>
 * <seealso name="ChangeVehicleColours" />
 * <seealso name="ChangeVehiclePaintjob" />
 * <seealso name="OnVehiclePaintjob" />
 * <seealso name="OnVehicleMod" />
 * <seealso name="OnEnterExitModShop" />
 * <remarks>Previewing a component inside a mod shop might call this callback.</remarks>
 * <remarks>This callback is not called by <a href="#ChangeVehicleColor">ChangeVehicleColor</a>.</remarks>
 * <returns>
 *   Returning <b><c>0</c></b> in this callback will deny the colour change.  Returning <b><c>1</c></b>
 * will allow it.  This can be used to prevent hackers from changing vehicle colours using cheats.<br
 * />
 *   It is always called first in gamemode so returning <b><c>0</c></b> there also blocks other filterscripts
 * from seeing it.
 * </returns>
 */
forward OnVehicleRespray(playerid, vehicleid, color1, color2);

/**
 * <summary>This callback is called when a vehicle element such as doors, tires, panels, or lights change
 * their damage status.</summary>
 * <param name="vehicleid">The ID of the vehicle that was changed its damage status</param>
 * <param name="playerid">The ID of the player who synced the change in the damage status (who had the
 * car damaged or repaired)</param>
 * <seealso name="GetVehicleDamageStatus" />
 * <seealso name="UpdateVehicleDamageStatus" />
 * <remarks>This does not include vehicle health changes</remarks>
 * <returns>
 *   <b><c>1</c></b> - Will prevent other filterscripts from receiving this callback.<br />
 *   <b><c>0</c></b> - Indicates that this callback will be passed to the next filterscript.<br />
 *   It is always called first in filterscripts.<br />
 * </returns>
 */
forward OnVehicleDamageStatusUpdate(vehicleid, playerid);

/**
 * <summary>This callback is called when a player's client updates/syncs the position of a vehicle they're
 * not driving.  This can happen outside of the vehicle or when the player is a passenger of a vehicle
 * that has no driver.</summary>
 * <param name="vehicleid">The ID of the vehicle that's position was updated</param>
 * <param name="playerid">The ID of the player that sent a vehicle position sync update</param>
 * <param name="passenger_seat">The ID of the seat if the player is a passenger.  0=not in vehicle,
 * 1=front passenger, 2=backleft 3=backright 4+ is for coach/bus etc.  with many passenger seats</param>
 * <param name="new_x">The new X coordinate of the vehicle.</param>
 * <param name="new_y">The new Y coordinate of the vehicle.</param>
 * <param name="new_z">The new Z coordinate of the vehicle.</param>
 * <param name="vel_x">The new X velocity of the vehicle.</param>
 * <param name="vel_y">The new Y velocity of the vehicle.</param>
 * <param name="vel_z">The new Z velocity of the vehicle.</param>
 * <seealso name="OnTrailerUpdate" />
 * <remarks>This callback is called very frequently per second per unoccupied vehicle.  You should refrain
 * from implementing intensive calculations or intensive file writing/reading operations in this callback.</remarks>
 * <remarks><a href="#GetVehiclePos">GetVehiclePos</a> will return the old coordinates of the vehicle
 * before this update.</remarks>
 * <returns>
 *   Returning <b><c>0</c></b> in this callback will stop the vehicle's position being synced to other
 * players.  Update is still sent to the updating player.  Useful for combating vehicle teleport hacks.<br
 * />
 *   It is always called first in filterscripts so returning <b><c>0</c></b> there also blocks other
 * scripts from seeing it.
 * </returns>
 */
forward OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);
