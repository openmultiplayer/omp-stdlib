#if defined _INC_omp_object
	#endinput
#endif
#define _INC_omp_object

/**
 * <library name="omp_object" summary="open.mp object functions.">
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
 * <library>omp_object</library>
 */
#if defined MAX_OBJECTS
	#if MAX_OBJECTS < 1 || MAX_OBJECTS > 2000
		#error MAX_OBJECTS must be >= 1 and <= 2000
	#endif

	const __MAX_OBJECTS                        = MAX_OBJECTS;
	#define __MAX_OBJECTS
#else
	const MAX_OBJECTS                          = 2000;
	#define MAX_OBJECTS                        2000
#endif

/**
 * <library>omp_object</library>
 */
#if defined MAX_OBJECT_MATERIAL_SLOTS
	#if MAX_OBJECT_MATERIAL_SLOTS < 1 || MAX_OBJECT_MATERIAL_SLOTS > 16
		#error MAX_OBJECT_MATERIAL_SLOTS must be >= 1 and <= 16
	#endif

	const __MAX_OBJECT_MATERIAL_SLOTS      	   = MAX_OBJECT_MATERIAL_SLOTS;
	#define __MAX_OBJECT_MATERIAL_SLOTS
#else
	const MAX_OBJECT_MATERIAL_SLOTS            = 16;
	#define MAX_OBJECT_MATERIAL_SLOTS          16
#endif

/**
 * <library>omp_object</library>
 */
const INVALID_OBJECT_ID                        = 0xFFFF;
#define INVALID_OBJECT_ID                      65535

/// <p/>
/**
 * <library>omp_object</library>
 */
#define SELECT_OBJECT: __TAG(SELECT_OBJECT):
enum SELECT_OBJECT:__SELECT_OBJECT
{
	UNKNOWN_SELECT_OBJECT                      = -1,
	SELECT_OBJECT_GLOBAL_OBJECT                = 1,
	SELECT_OBJECT_PLAYER_OBJECT
}
static stock SELECT_OBJECT:_@SELECT_OBJECT() { return __SELECT_OBJECT; }

#define UNKNOWN_SELECT_OBJECT                  (SELECT_OBJECT:-1)
#define SELECT_OBJECT_GLOBAL_OBJECT            (SELECT_OBJECT:1)
#define SELECT_OBJECT_PLAYER_OBJECT            (SELECT_OBJECT:2)

/// <p/>
/**
 * <library>omp_object</library>
 */
#define OBJECT_MATERIAL_SIZE: __TAG(OBJECT_MATERIAL_SIZE):
enum OBJECT_MATERIAL_SIZE:__OBJECT_MATERIAL_SIZE (+= 10)
{
	UNKNOWN_OBJECT_MATERIAL_SIZE               = -1,
	OBJECT_MATERIAL_SIZE_32x32                 = 10,
	OBJECT_MATERIAL_SIZE_64x32,
	OBJECT_MATERIAL_SIZE_64x64,
	OBJECT_MATERIAL_SIZE_128x32,
	OBJECT_MATERIAL_SIZE_128x64,
	OBJECT_MATERIAL_SIZE_128x128,
	OBJECT_MATERIAL_SIZE_256x32,
	OBJECT_MATERIAL_SIZE_256x64,
	OBJECT_MATERIAL_SIZE_256x128,
	OBJECT_MATERIAL_SIZE_256x256,
	OBJECT_MATERIAL_SIZE_512x64,
	OBJECT_MATERIAL_SIZE_512x128,
	OBJECT_MATERIAL_SIZE_512x256,
	OBJECT_MATERIAL_SIZE_512x512
}
static stock OBJECT_MATERIAL_SIZE:_@OBJECT_MATERIAL_SIZE() { return __OBJECT_MATERIAL_SIZE; }

#define UNKNOWN_OBJECT_MATERIAL_SIZE           (OBJECT_MATERIAL_SIZE:-1)
#define OBJECT_MATERIAL_SIZE_32x32             (OBJECT_MATERIAL_SIZE:10)
#define OBJECT_MATERIAL_SIZE_64x32             (OBJECT_MATERIAL_SIZE:20)
#define OBJECT_MATERIAL_SIZE_64x64             (OBJECT_MATERIAL_SIZE:30)
#define OBJECT_MATERIAL_SIZE_128x32            (OBJECT_MATERIAL_SIZE:40)
#define OBJECT_MATERIAL_SIZE_128x64            (OBJECT_MATERIAL_SIZE:50)
#define OBJECT_MATERIAL_SIZE_128x128           (OBJECT_MATERIAL_SIZE:60)
#define OBJECT_MATERIAL_SIZE_256x32            (OBJECT_MATERIAL_SIZE:70)
#define OBJECT_MATERIAL_SIZE_256x64            (OBJECT_MATERIAL_SIZE:80)
#define OBJECT_MATERIAL_SIZE_256x128           (OBJECT_MATERIAL_SIZE:90)
#define OBJECT_MATERIAL_SIZE_256x256           (OBJECT_MATERIAL_SIZE:100)
#define OBJECT_MATERIAL_SIZE_512x64            (OBJECT_MATERIAL_SIZE:110)
#define OBJECT_MATERIAL_SIZE_512x128           (OBJECT_MATERIAL_SIZE:120)
#define OBJECT_MATERIAL_SIZE_512x256           (OBJECT_MATERIAL_SIZE:130)
#define OBJECT_MATERIAL_SIZE_512x512           (OBJECT_MATERIAL_SIZE:140)

/// <p/>
/**
 * <library>omp_object</library>
 */
#define OBJECT_MATERIAL_TEXT_ALIGN: __TAG(OBJECT_MATERIAL_TEXT_ALIGN):
enum OBJECT_MATERIAL_TEXT_ALIGN:__OBJECT_MATERIAL_TEXT_ALIGN
{
	// First so we don't have trailing commas.
#if __namemax > 31
	UNKNOWN_OBJECT_MATERIAL_TEXT_ALIGN         = -1,
	OBJECT_MATERIAL_TEXT_ALIGN_CENTRE          = 1,
	OBJECT_MATERIAL_TEXT_ALIGN_CENTER          = 1,
	OBJECT_MATERIAL_TEXT_ALIGN_RIGHT           = 2,
#endif
	OBJECT_MATERIAL_TEXT_ALIGN_LEFT            = 0,
	OBJECT_MATERIAL_TEXT_ALIGN_CENT            = 1,
	OBJECT_MATERIAL_TEXT_ALIGN_RIGT            = 2
}
static stock OBJECT_MATERIAL_TEXT_ALIGN:_@OBJECT_MATERIAL_TEXT_ALIGN() { return __OBJECT_MATERIAL_TEXT_ALIGN; }

#if __namemax > 31
#define UNKNOWN_OBJECT_MATERIAL_TEXT_ALIGN     (OBJECT_MATERIAL_TEXT_ALIGN:-1)
#define OBJECT_MATERIAL_TEXT_ALIGN_CENTRE      (OBJECT_MATERIAL_TEXT_ALIGN:1)
#define OBJECT_MATERIAL_TEXT_ALIGN_CENTER      (OBJECT_MATERIAL_TEXT_ALIGN:1)
#define OBJECT_MATERIAL_TEXT_ALIGN_RIGHT       (OBJECT_MATERIAL_TEXT_ALIGN:2)
#endif
#define OBJECT_MATERIAL_TEXT_ALIGN_LEFT        (OBJECT_MATERIAL_TEXT_ALIGN:0)
#define OBJECT_MATERIAL_TEXT_ALIGN_CENT        (OBJECT_MATERIAL_TEXT_ALIGN:1)
#define OBJECT_MATERIAL_TEXT_ALIGN_RIGT        (OBJECT_MATERIAL_TEXT_ALIGN:2)

/// <p/>
/**
 * <library>omp_object</library>
 */
#define EDIT_RESPONSE: __TAG(EDIT_RESPONSE):
enum EDIT_RESPONSE:__EDIT_RESPONSE
{
	UNKNOWN_EDIT_RESPONSE                      = -1,
	EDIT_RESPONSE_CANCEL,
	EDIT_RESPONSE_FINAL,
	EDIT_RESPONSE_UPDATE
}
static stock EDIT_RESPONSE:_@EDIT_RESPONSE() { return __EDIT_RESPONSE; }

#define UNKNOWN_EDIT_RESPONSE                  (EDIT_RESPONSE:-1)
#define EDIT_RESPONSE_CANCEL                   (EDIT_RESPONSE:0)
#define EDIT_RESPONSE_FINAL                    (EDIT_RESPONSE:1)
#define EDIT_RESPONSE_UPDATE                   (EDIT_RESPONSE:2)

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
 * <library>omp_object</library>
 * <summary>Allows camera collisions with newly created objects to be disabled by default.</summary>
 * <param name="disable"><b><c>1</c></b> to disable camera collisions for newly created objects and
 * <b><c>0</c></b> to enable them (enabled by default)</param>
 * <seealso name="SetObjectNoCameraCol" />
 * <seealso name="SetPlayerObjectNoCameraCol" />
 * <remarks>This function only affects the camera collision of objects created AFTER its use - it does
 * not toggle existing objects' camera collisions.</remarks>
 * <remarks>This only works outside the map boundaries (past <b><c>-3000</c></b>/<b><c>3000</c></b>
 * units on the x and/or y axis).</remarks>
 */
#if __namemax > 31
	native bool:SetObjectsDefaultCameraCollision(bool:disable);
#endif

#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `SetObjectsDefaultCameraCollision`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native bool:SetObjectsDefaultCameraCol(bool:disable);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native GetObjectType(playerid, objectid);

/*
native # Global();
native             Global(
native      ====================(
native
*/

/**
 * <library>omp_object</library>
 * <summary>Creates an object at specified coordinates in the game world.</summary>
 * <param name="modelid">The model to create</param>
 * <param name="x">The x coordinate to create the object at</param>
 * <param name="y">The y coordinate to create the object at</param>
 * <param name="z">The z coordinate to create the object at</param>
 * <param name="rotationX">The x rotation of the object</param>
 * <param name="rotationY">The y rotation of the object</param>
 * <param name="rotationZ">The z rotation of the object</param>
 * <param name="drawDistance">The distance that San Andreas renders objects at. <b><c>0.0</c></b> will
 * cause objects to render at their default distances. <b>Usable since 0.3b, limited to <c>300</c> prior
 * to 0.3x</b> (optional=<b><c>0.0</c></b>)</param>
 * <seealso name="DestroyObject" />
 * <seealso name="IsValidObject" />
 * <seealso name="CreatePlayerObject" />
 * <seealso name="MoveObject" />
 * <seealso name="SetObjectPos" />
 * <seealso name="SetObjectRot" />
 * <seealso name="GetObjectPos" />
 * <seealso name="GetObjectRot" />
 * <seealso name="AttachObjectToPlayer" />
 * <seealso name="SetObjectMaterialText" />
 * <seealso name="SetObjectMaterial" />
 * <remarks>
 *   Objects that emit light (lampposts, police lights, bollard lights, neons etc.) that have a greater
 * rotation than <b><c>16.26</c></b> degrees (or <b><c>-16.26</c></b>) on either the x or y axis will
 * stop shining.  This effect also applies to light objects attached to other objects, players and vehicles.
 *   If a light object is attached to a car and the car is rotated over <b><c>16.26</c></b> degrees
 * (like in a rollover), the object will also stop emitting light.  This is a GTA:SA issue and is not
 * caused by a bug in open.mp.
 * </remarks>
 * <remarks>In case the light is attached to another object, one fix for this is to set <b>SyncRotation</b>
 * to false in <a href="#AttachObjectToObject">AttachObjectToObject</a>.  This will ensure the light
 * stays at <b><c>0</c></b> rotation.  This would only really work for objects that consist ONLY of
 * light, so wouldn't work for the police light for example. </remarks>
 * <remarks>There is a limit of <a href="https://open.mp/docs/scripting/resources/limits"><b><c>1000</c></b> objects
 * (<b><c>MAX_OBJECTS</c></b>)</a>.  To circumvent this limit, you can use a
 * <a href="https://github.com/samp-incognito/samp-streamer-plugin/tree/open.mp">streamer</a></remarks>
 * <returns>The ID of the object that was created, or <b><c>INVALID_OBJECT_ID</c></b> if the object
 * limit (<b><c>MAX_OBJECTS</c></b>) was reached.</returns>
 */
native CreateObject(modelid, Float:x, Float:y, Float:z, Float:rotationX, Float:rotationY, Float:rotationZ, Float:drawDistance = 0.0);

/**
 * <library>omp_object</library>
 * <summary>Attach an object to a vehicle.</summary>
 * <param name="objectid">The ID of the object to attach to the vehicle.  Note that this is an object
 * ID, not a model ID.  The object must be CreateObject created first</param>
 * <param name="vehicleid">The ID of the vehicle to attach the object to</param>
 * <param name="offsetX">The x axis offset from the vehicle to attach the object to</param>
 * <param name="offsetY">The y axis offset from the vehicle to attach the object to</param>
 * <param name="offsetZ">The z axis offset from the vehicle to attach the object to</param>
 * <param name="rotationX">The x rotation offset for the object</param>
 * <param name="rotationY">The y rotation offset for the object</param>
 * <param name="rotationZ">The z rotation offset for the object</param>
 * <seealso name="AttachObjectToPlayer" />
 * <seealso name="AttachObjectToObject" />
 * <seealso name="AttachPlayerObjectToVehicle" />
 * <seealso name="CreateObject" />
 * <remarks>The object must be created first.</remarks>
 * <remarks>When the vehicle is destroyed or respawned, the attached objects won't be destroyed with
 * it; they will remain stationary at the position the vehicle disappeared and be reattached to the
 * next vehicle to claim the vehicle ID that the objects were attached to.</remarks>
 */
native bool:AttachObjectToVehicle(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotationX, Float:rotationY, Float:rotationZ);

/**
 * <library>omp_object</library>
 * <summary>You can use this function to attach objects to other objects.  The objects will folow the
 * main object.</summary>
 * <param name="objectid">The object to attach to another object</param>
 * <param name="attachtoid">The object to attach the object to</param>
 * <param name="offsetX">The distance between the main object and the object in the x direction</param>
 * <param name="offsetY">The distance between the main object and the object in the y direction</param>
 * <param name="offsetZ">The distance between the main object and the object in the z direction</param>
 * <param name="rotationX">The x rotation between the object and the main object</param>
 * <param name="rotationY">The y rotation between the object and the main object</param>
 * <param name="rotationZ">The z rotation between the object and the main object</param>
 * <param name="syncRotation">If set to <b><c>0</c></b>, objectid's rotation will not change with <paramref
 * name="attachtoid" />'s (optional=<b><c>1</c></b>)</param>
 * <seealso name="AttachObjectToPlayer" />
 * <seealso name="AttachObjectToVehicle" />
 * <seealso name="CreateObject" />
 * <remarks>
 *   <ul>
 *     <li>Both objects need to be created before attempting to attach them.</li>
 * it will not be supported by streamers.</li>
 *   </ul>
 * </remarks>
 * <returns>
 * <b><c>1</c></b>: The function executed successfully.<br />
 * <b><c>0</c></b>: The function failed to execute.  This means the first object (<paramref name="objectid"
 * />) does not exist.  There are no internal checks to verify that the second object (<paramref name="attachtoid"
 * />) exists.
 * </returns>
 */
native bool:AttachObjectToObject(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotationX, Float:rotationY, Float:rotationZ, bool:syncRotation = true);

/**
 * <library>omp_object</library>
 * <summary>Attach an object to a player.</summary>
 * <param name="objectid">The ID of the object to attach to the player</param>
 * <param name="playerid">The ID of the player to attach the object to</param>
 * <param name="offsetX">The distance between the player and the object in the x direction</param>
 * <param name="offsetY">The distance between the player and the object in the y direction</param>
 * <param name="offsetZ">The distance between the player and the object in the z direction</param>
 * <param name="rotationX">The x rotation between the object and the player</param>
 * <param name="rotationY">The y rotation between the object and the player</param>
 * <param name="rotationZ">The z rotation between the object and the player</param>
 * <seealso name="AttachObjectToVehicle" />
 * <seealso name="AttachObjectToObject" />
 * <seealso name="AttachPlayerObjectToPlayer" />
 * <seealso name="SetPlayerAttachedObject" />
 * <seealso name="CreateObject" />
 * <returns>This function always returns <b><c>0</c></b>.</returns>
 */
native bool:AttachObjectToPlayer(objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotationX, Float:rotationY, Float:rotationZ);

/**
 * <library>omp_object</library>
 * <summary>Change the position of an object.</summary>
 * <param name="objectid">The ID of the object to set the position of.  Returned by <a href="#CreateObject">CreateObject</a></param>
 * <param name="x">The x coordinate to position the object at</param>
 * <param name="y">The y coordinate to position the object at</param>
 * <param name="z">The z coordinate to position the object at</param>
 * <seealso name="GetObjectPos" />
 * <seealso name="SetObjectRot" />
 * <seealso name="GetPlayerObjectPos" />
 * <seealso name="CreateObject" />
 * <returns>This function always returns <b><c>1</c></b>, even if the object specified does not exist.</returns>
 */
native bool:SetObjectPos(objectid, Float:x, Float:y, Float:z);

/**
 * <library>omp_object</library>
 * <summary>Get the position of an object.</summary>
 * <param name="objectid">The ID of the object to get the position of.</param>
 * <param name="x">A variable in which to store the x coordinate, passed by reference</param>
 * <param name="y">A variable in which to store the y coordinate, passed by reference</param>
 * <param name="z">A variable in which to store the z coordinate, passed by reference</param>
 * <seealso name="SetObjectPos" />
 * <seealso name="GetObjectRot" />
 * <seealso name="SetPlayerObjectPos" />
 * <seealso name="CreateObject" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The specified object does not exist.
 * </returns>
 */
native bool:GetObjectPos(objectid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_object</library>
 * <summary>Set the rotation of an object on the three axes (x, y and z).</summary>
 * <param name="objectid">The ID of the object to set the rotation of</param>
 * <param name="rotationX">The x rotation</param>
 * <param name="rotationY">The y rotation</param>
 * <param name="rotationZ">The z rotation</param>
 * <seealso name="GetObjectRot" />
 * <seealso name="GetObjectPos" />
 * <seealso name="CreateObject" />
 * <seealso name="SetPlayerObjectRot" />
 * <returns>This function always returns <b><c>1</c></b>, even if the object doesn't exist.</returns>
 */
native bool:SetObjectRot(objectid, Float:rotationX, Float:rotationY, Float:rotationZ);

/**
 * <library>omp_object</library>
 * <summary>Use this function to get the objects current rotation.  The rotation is saved by reference
 * in three rotationX/rotationY/rotationZ variables.</summary>
 * <param name="objectid">The objectid of the object you want to get the rotation from</param>
 * <param name="rotationX">The variable to store the x rotation, passed by reference</param>
 * <param name="rotationY">The variable to store the y rotation, passed by reference</param>
 * <param name="rotationZ">The variable to store the z rotation, passed by reference</param>
 * <seealso name="SetObjectRot" />
 * <seealso name="SetObjectPos" />
 * <seealso name="SetPlayerObjectRot" />
 * <seealso name="CreateObject" />
 * <returns>The object's rotation is stored in the referenced variables, not in the return value.</returns>
 */
native bool:GetObjectRot(objectid, &Float:rotationX, &Float:rotationY, &Float:rotationZ);

/**
 * <library>omp_object</library>
 * <summary>Get the model ID of an object.</summary>
 * <param name="objectid">The ID of the object to get the model of</param>
 * <seealso name="GetPlayerObjectModel" />
 * <seealso name="CreateObject" />
 * <returns>The model ID of the object. <b><c>-1</c></b> if <paramref name="objectid" /> does not exist.</returns>
 */
native GetObjectModel(objectid);

/**
 * <library>omp_object</library>
 * <summary>Disable collisions between players' cameras and the specified object.</summary>
 * <param name="objectid">The ID of the object to disable camera collisions on</param>
 * <seealso name="SetObjectsDefaultCameraCol" />
 * <seealso name="SetPlayerObjectNoCameraCol" />
 * <remarks>This only works outside the map boundaries (past <b><c>-3000</c></b>/<b><c>3000</c></b>
 * units on the x and/or y axis).</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The object specified does not exist.
 * </returns>
 */
native bool:SetObjectNoCameraCollision(objectid) = SetObjectNoCameraCol;

/**
 * <library>omp_object</library>
 * <summary>Disable collisions between players' cameras and the specified object.</summary>
 * <param name="objectid">The ID of the object to disable camera collisions on</param>
 * <seealso name="SetObjectsDefaultCameraCol" />
 * <seealso name="SetPlayerObjectNoCameraCol" />
 * <remarks>This only works outside the map boundaries (past <b><c>-3000</c></b>/<b><c>3000</c></b>
 * units on the x and/or y axis).</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The object specified does not exist.
 * </returns>
 */
native bool:SetObjectNoCameraCol(objectid);

/**
 * <library>omp_object</library>
 * <summary>Checks if an object with the ID provided exists.</summary>
 * <param name="objectid">The ID of the object to check the existence of</param>
 * <seealso name="IsValidPlayerObject" />
 * <seealso name="CreateObject" />
 * <seealso name="DestroyObject" />
 * <remarks>This is to check if an object exists, not if a model is valid.</remarks>
 * <returns><b><c>1</c></b> if the object exists, <b><c>0</c></b> if not.</returns>
 */
native bool:IsValidObject(objectid);

/**
 * <library>omp_object</library>
 * <summary>Destroys (removes) an object that was created using <a href="#CreateObject">CreateObject</a>.</summary>
 * <param name="objectid">The ID of the object to destroy.  Returned by <a href="#CreateObject">CreateObject</a></param>
 * <seealso name="CreateObject" />
 * <seealso name="IsValidObject" />
 * <seealso name="DestroyPlayerObject" />
 */
native bool:DestroyObject(objectid);

/**
 * <library>omp_object</library>
 * <summary>Move an object to a new position with a set speed.  Players/vehicles will 'surf' the object
 * as it moves.</summary>
 * <param name="objectid">The ID of the object to move</param>
 * <param name="targetX">The x coordinate to move the object to</param>
 * <param name="targetY">The y coordinate to move the object to</param>
 * <param name="targetZ">The z coordinate to move the object to</param>
 * <param name="speed">The speed at which to move the object (units per second)</param>
 * <param name="rotationX">The FINAL x rotation (optional=<b><c>-1000.0</c></b>)</param>
 * <param name="rotationY">The FINAL y rotation (optional=<b><c>-1000.0</c></b>)</param>
 * <param name="rotationZ">The FINAL z rotation (optional=<b><c>-1000.0</c></b>)</param>
 * <seealso name="OnObjectMoved" />
 * <seealso name="IsObjectMoving" />
 * <seealso name="StopObject" />
 * <seealso name="MovePlayerObject" />
 * <seealso name="SetObjectPos" />
 * <seealso name="SetObjectRot" />
 * <seealso name="CreateObject" />
 * <remarks>This function can be used to make objects rotate smoothly.  In order to achieve this however,
 * the object must also be <b>moved</b>.  The specified rotation is the rotation the object will have
 * after the movement.  Hence the object will not rotate when no movement is applied.</remarks>
 * <remarks>To fully understand the above note, you can (but not limited to) increase the z position
 * by <b><c>(+0.001</c></b>) and then (<b><c>-0.001</c></b>) after moving it again, as not changing
 * the x, y or z will not rotate the object. </remarks>
 * <returns>The time it will take for the object to move in milliseconds.</returns>
 */
native bool:MoveObject(objectid, Float:targetX, Float:targetY, Float:targetZ, Float:speed, Float:rotationX = -1000.0, Float:rotationY = -1000.0, Float:rotationZ = -1000.0);

/**
 * <library>omp_object</library>
 * <summary>Replace the texture of an object with the texture from another model in the game.</summary>
 * <param name="objectid">The ID of the object to change the texture of</param>
 * <param name="materialIndex">The material index on the object to change (<b><c>0</c></b> to <b><c>15</c></b>)</param>
 * <param name="modelid">The modelid on which the replacement texture is located.  Use <b><c>0</c></b>
 * for alpha.  Use <b><c>-1</c></b> to change the material colour without altering the texture</param>
 * <param name="textureLibrary">The name of the txd file which contains the replacement texture (use
 * <b><c>"none"</c></b> if not required)</param>
 * <param name="textureName">The name of the texture to use as the replacement (use <b><c>"none"</c></b>
 * if not required)</param>
 * <param name="materialColour">The object colour to set, as an integer or hex in <b>ARGB</b> colour
 * format.  Using <b><c>0</c></b> keeps the existing material colour (optional=<b><c>0</c></b>)</param>
 * <seealso name="SetPlayerObjectMaterial" />
 * <seealso name="SetObjectMaterialText" />
 * <remarks>Vertex lightning of the object will disappear if material colour is changed.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.
 * </returns>
 */
native bool:SetObjectMaterial(objectid, materialIndex, modelid, const textureLibrary[], const textureName[], materialColour = 0);

/**
 * <library>omp_object</library>
 * <summary>Replace the texture of an object with text.</summary>
 * <param name="objectid">The ID of the object to replace the texture of with text</param>
 * <param name="text">The text to show on the object. (MAX <b>2048</b> characters).  May be optionally formatted</param>
 * <param name="materialIndex">The object's material index to replace with text (optional=<b><c>0</c></b>)</param>
 * <param name="materialSize">The size of the material (optional=<b><c>OBJECT_MATERIAL_SIZE_256x128</c></b>)</param>
 * <param name="fontFace">The font to use (optional=<b><c>"Arial"</c></b>)</param>
 * <param name="fontSize">The size of the text (MAX <b>255</b>) (optional=<b><c>24</c></b>)</param>
 * <param name="bold">Bold text.  Set to <b><c>1</c></b> for bold, <b><c>0</c></b> for not (optional=<b><c>1</c></b>)</param>
 * <param name="fontColour">The colour of the text, in <b>ARGB</b> format (optional=<b><c>-1</c></b>)</param>
 * <param name="backgroundColour">The background colour, in <b>ARGB</b> format (optional=<b><c>0</c></b>)</param>
 * <param name="textAlignment">The alignment of the text (optional=<b><c>OBJECT_MATERIAL_TEXT_ALIGN_LEFT</c></b>)</param>
 * <seealso name="SetPlayerObjectMaterialText" />
 * <seealso name="SetObjectMaterial" />
 * <remarks>Color embedding can be used for multiple colours in the text.</remarks>
 * <remarks>
 *   <b>Alignment:</b><br />
 *   <ul>
 *     <li><b><c>OBJECT_MATERIAL_TEXT_ALIGN_LEFT</c></b> 0</li>
 *     <li><b><c>OBJECT_MATERIAL_TEXT_ALIGN_CENTER</c></b> 1</li>
 *     <li><b><c>OBJECT_MATERIAL_TEXT_ALIGN_RIGHT</c></b> 2</li>
 *   </ul>
 * </remarks>
 * <remarks>
 *   <b>Sizes:</b><br />
 *   <ul>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_32x32</c></b> 10</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_64x32</c></b> 20</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_64x64</c></b> 30</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_128x32</c></b> 40</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_128x64</c></b> 50</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_128x128</c></b> 60</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_256x32</c></b> 70</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_256x64</c></b> 80</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_256x128</c></b> 90</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_256x256</c></b> 100</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_512x64</c></b> 110</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_512x128</c></b> 120</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_512x256</c></b> 130</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_512x512</c></b> 140</li>
 *   </ul>
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.
 * </returns>
 */
native bool:SetObjectMaterialText(objectid, const text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, const fontFace[] = "Arial", fontSize = 24, bool:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textAlignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT, OPEN_MP_TAGS:...);

/**
 * <library>omp_object</library>
 * <summary>Stop a moving object after <a href="#MoveObject">MoveObject</a> has been used.</summary>
 * <param name="objectid">The ID of the object to stop moving</param>
 * <seealso name="MoveObject" />
 * <seealso name="IsObjectMoving" />
 * <seealso name="OnObjectMoved" />
 * <seealso name="StopPlayerObject" />
 */
native bool:StopObject(objectid);

/**
 * <library>omp_object</library>
 * <summary>Checks if the given objectid is moving.</summary>
 * <param name="objectid">The objectid you want to check if is moving</param>
 * <seealso name="MoveObject" />
 * <seealso name="StopObject" />
 * <seealso name="OnObjectMoved" />
 * <seealso name="IsPlayerObjectMoving" />
 * <returns><b><c>1</c></b> if the object is moving, <b><c>0</c></b> if not.</returns>
 */
native bool:IsObjectMoving(objectid);

/**
 * <library>omp_object</library>
 * <summary>Allows a player to edit an object (position and rotation) using their mouse on a GUI (Graphical
 * User Interface).</summary>
 * <param name="playerid">The ID of the player that should edit the object</param>
 * <param name="objectid">The ID of the object to be edited by the player</param>
 * <seealso name="EditPlayerObject" />
 * <seealso name="EditAttachedObject" />
 * <seealso name="SelectObject" />
 * <seealso name="CancelEdit" />
 * <remarks>You can move the camera while editing by pressing and holding the <b>spacebar</b> (or <b>W</b>
 * in vehicle) and moving your mouse.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  Success is reported when a non-existent object
 * is specified, but nothing will happen.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player is not connected.
 * </returns>
 */
native bool:BeginObjectEditing(playerid, objectid);

/**
 * <library>omp_object</library>
 * <summary>Allows a player to edit an object (position and rotation) using their mouse on a GUI (Graphical
 * User Interface).</summary>
 * <param name="playerid">The ID of the player that should edit the object</param>
 * <param name="objectid">The ID of the object to be edited by the player</param>
 * <seealso name="EditPlayerObject" />
 * <seealso name="EditAttachedObject" />
 * <seealso name="SelectObject" />
 * <seealso name="CancelEdit" />
 * <remarks>You can move the camera while editing by pressing and holding the <b>spacebar</b> (or <b>W</b>
 * in vehicle) and moving your mouse.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  Success is reported when a non-existent object
 * is specified, but nothing will happen.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player is not connected.
 * </returns>
 */
native bool:EditObject(playerid, objectid) = BeginObjectEditing;

/**
 * <library>omp_object</library>
 * <summary>Display the cursor and allow the player to select an object. <a href="#OnPlayerSelectObject">OnPlayerSelectObject</a>
 * is called when the player selects an object.</summary>
 * <param name="playerid">The ID of the player that should be able to select the object</param>
 * <seealso name="EditObject" />
 * <seealso name="EditPlayerObject" />
 * <seealso name="EditAttachedObject" />
 * <seealso name="CancelEdit" />
 * <seealso name="OnPlayerSelectObject" />
 */
native bool:BeginObjectSelecting(playerid);

/**
 * <library>omp_object</library>
 * <summary>Display the cursor and allow the player to select an object. <a href="#OnPlayerSelectObject">OnPlayerSelectObject</a>
 * is called when the player selects an object.</summary>
 * <param name="playerid">The ID of the player that should be able to select the object</param>
 * <seealso name="EditObject" />
 * <seealso name="EditPlayerObject" />
 * <seealso name="EditAttachedObject" />
 * <seealso name="CancelEdit" />
 * <seealso name="OnPlayerSelectObject" />
 */
native bool:SelectObject(playerid) = BeginObjectSelecting;

/**
 * <library>omp_object</library>
 * <summary>Cancel object edition mode for a player.</summary>
 * <param name="playerid">The ID of the player to cancel edition for</param>
 * <seealso name="SelectObject" />
 * <seealso name="EditObject" />
 * <seealso name="EditPlayerObject" />
 * <seealso name="EditAttachedObject" />
 */
native bool:EndObjectEditing(playerid);

/**
 * <library>omp_object</library>
 * <summary>Cancel object edition mode for a player.</summary>
 * <param name="playerid">The ID of the player to cancel edition for</param>
 * <seealso name="SelectObject" />
 * <seealso name="EditObject" />
 * <seealso name="EditPlayerObject" />
 * <seealso name="EditAttachedObject" />
 */
native bool:CancelEdit(playerid) = EndObjectEditing;

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native Float:GetObjectDrawDistance(objectid);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:SetObjectMoveSpeed(objectid, Float:speed);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native Float:GetObjectMoveSpeed(objectid);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetObjectMovingTargetPos(objectid, &Float:targetX, &Float:targetY, &Float:targetZ);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetObjectTarget(objectid, &Float:targetX = 0.0, &Float:targetY = 0.0, &Float:targetZ = 0.0) = GetObjectMovingTargetPos;

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetObjectMovingTargetRot(objectid, &Float:rotationX, &Float:rotationY, &Float:rotationZ);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetObjectAttachedData(objectid, &parentVehicle = 0, &parentObject = 0, &parentPlayer = 0);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetObjectAttachedOffset(objectid, &Float:offsetX = 0.0, &Float:offsetY = 0.0, &Float:offsetZ = 0.0, &Float:rotationX = 0.0, &Float:rotationY = 0.0, &Float:rotationZ = 0.0);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetObjectSyncRotation(objectid);

/**
 * <library>omp_object</library>
 * <remarks>This is NOT a boolean return.</remarks>
 * <summary>Get the type of material slot usage.  0 - None, 1 - Material, 2 - Text.</summary>
 */
native IsObjectMaterialSlotUsed(objectid, materialIndex);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetObjectMaterial(objectid, materialIndex, &modelid, textureLibrary[], textureLibrarySize = sizeof (textureLibrary), textureName[], textureNameSize = sizeof (textureName), &materialColour = 0);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetObjectMaterialText(objectid, materialIndex, text[], textSize = sizeof (text), &OBJECT_MATERIAL_SIZE:materialSize, fontFace[], fontFaceSize = sizeof (fontFace), &fontSize = 0, &bool:bold = true, &fontColour = 0xFFFFFFFF, &backgroundColour = 0, &OBJECT_MATERIAL_TEXT_ALIGN:textAlignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:IsObjectNoCameraCol(objectid);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
stock bool:HasObjectCameraCollision(objectid)
{
	return !IsObjectNoCameraCol(objectid);
}

/*
native # Per-Player();
native           Per-Player(
native      ====================(
native
*/

/**
 * <library>omp_object</library>
 * <summary>Creates an object which will be visible to only one player.</summary>
 * <param name="playerid">The ID of the player to create the object for</param>
 * <param name="modelid">The model to create</param>
 * <param name="x">The x coordinate to create the object at</param>
 * <param name="y">The y coordinate to create the object at</param>
 * <param name="z">The z coordinate to create the object at</param>
 * <param name="rotationX">The x rotation of the object</param>
 * <param name="rotationY">The y rotation of the object</param>
 * <param name="rotationZ">The z rotation of the object</param>
 * <param name="drawDistance">The distance from which objects will appear to players. <b><c>0.0</c></b>
 * will cause an object to render at its default distance.  Leaving this parameter out will cause objects
 * to be rendered at their default distance.</param>
 * <seealso name="CreateObject" />
 * <seealso name="IsValidPlayerObject" />
 * <seealso name="DestroyPlayerObject" />
 * <seealso name="MovePlayerObject" />
 * <seealso name="StopPlayerObject" />
 * <seealso name="SetPlayerObjectPos" />
 * <seealso name="SetPlayerObjectRot" />
 * <seealso name="GetPlayerObjectPos" />
 * <seealso name="GetPlayerObjectRot" />
 * <seealso name="AttachPlayerObjectToPlayer" />
 * <seealso name="AttachObjectToPlayer" />
 * <returns>The ID of the object that was created, or <b><c>INVALID_OBJECT_ID</c></b> if the object
 * limit (<b><c>MAX_OBJECTS</c></b>) was reached.</returns>
 */
native CreatePlayerObject(playerid, modelid, Float:x, Float:y, Float:z, Float:rotationX, Float:rotationY, Float:rotationZ, Float:drawDistance = 0.0);

/**
 * <library>omp_object</library>
 * <summary>Attach a player object to a vehicle.</summary>
 * <param name="playerid">The ID of the player the object was created for</param>
 * <param name="objectid">The ID of the object to attach to the vehicle</param>
 * <param name="vehicleid">The ID of the vehicle to attach the object to</param>
 * <param name="offsetX">The x position offset for attachment</param>
 * <param name="offsetY">The y position offset for attachment</param>
 * <param name="offsetZ">The z position offset for attachment</param>
 * <param name="rotationX">The x rotation offset for attachment</param>
 * <param name="rotationY">The y rotation offset for attachment</param>
 * <param name="rotationZ">The z rotation offset for attachment</param>
 * <seealso name="CreatePlayerObject" />
 * <seealso name="AttachPlayerObjectToPlayer" />
 * <seealso name="AttachObjectToVehicle" />
 * <remarks>You need to create the object before attempting to attach it to a vehicle.</remarks>
 */
native bool:AttachPlayerObjectToVehicle(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotationX, Float:rotationY, Float:rotationZ);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:AttachPlayerObjectToObject(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotationX, Float:rotationY, Float:rotationZ, bool:syncRotation = true);

/**
 * <library>omp_object</library>
 * <summary>The same as AttachObjectToPlayer but for objects which were created for player.</summary>
 * <param name="playerid">The ID of the player which is linked with the object</param>
 * <param name="objectid">The objectid you want to attach to the player</param>
 * <param name="parentid">The ID of the player you want to attach to the object</param>
 * <param name="offsetX">The distance between the player and the object in the x direction</param>
 * <param name="offsetY">The distance between the player and the object in the y direction</param>
 * <param name="offsetZ">The distance between the player and the object in the z direction</param>
 * <param name="rotationX">The x rotation</param>
 * <param name="rotationY">The y rotation</param>
 * <param name="rotationZ">The z rotation</param>
 * <seealso name="SetPlayerAttachedObject" />
 * <seealso name="AttachPlayerObjectToVehicle" />
 * <seealso name="AttachObjectToPlayer" />
 * <seealso name="CreatePlayerObject" />
 */
native bool:AttachPlayerObjectToPlayer(playerid, objectid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ, Float:rotationX, Float:rotationY, Float:rotationZ);

/**
 * <library>omp_object</library>
 * <summary>Sets the position of a player-object to the specified coordinates.</summary>
 * <param name="playerid">The ID of the player whose player-object to set the position of</param>
 * <param name="objectid">The ID of the player-object to set the position of.  Returned by
 * <a href="#CreatePlayerObject">CreatePlayerObject</a></param>
 * <param name="x">The x coordinate to put the object at</param>
 * <param name="y">The y coordinate to put the object at</param>
 * <param name="z">The z coordinate to put the object at</param>
 * <seealso name="GetPlayerObjectPos" />
 * <seealso name="SetPlayerObjectRot" />
 * <seealso name="SetObjectPos" />
 * <seealso name="CreatePlayerObject" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  Player and/or object do not exist.
 * </returns>
 */
native bool:SetPlayerObjectPos(playerid, objectid, Float:x, Float:y, Float:z);

/**
 * <library>omp_object</library>
 * <summary>Get the position of a player object (<a href="#CreatePlayerObject">CreatePlayerObject</a>).</summary>
 * <param name="playerid">The ID of the player whose player object to get the position of</param>
 * <param name="objectid">The object's ID of which you want the current location</param>
 * <param name="x">A float variable in which to store the x coordinate, passed by reference</param>
 * <param name="y">A float variable in which to store the y coordinate, passed by reference</param>
 * <param name="z">A float variable in which to store the z coordinate, passed by reference</param>
 * <seealso name="" />
 * <seealso name="SetPlayerObjectPos" />
 * <seealso name="GetPlayerObjectRot" />
 * <seealso name="GetObjectPos" />
 * <seealso name="CreatePlayerObject" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player and/or the object don't exist.<br
 * />
 *   The object's position is stored in the specified variables.
 * </returns>
 */
native bool:GetPlayerObjectPos(playerid, objectid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_object</library>
 * <summary>Set the rotation of an object on the x, y and z axis.</summary>
 * <param name="playerid">The ID of the player whose player-object to rotate</param>
 * <param name="objectid">The ID of the player-object to rotate</param>
 * <param name="rotationX">The x rotation to set</param>
 * <param name="rotationY">The y rotation to set</param>
 * <param name="rotationZ">The z rotation to set</param>
 * <seealso name="GetPlayerObjectRot" />
 * <seealso name="SetPlayerObjectPos" />
 * <seealso name="SetObjectRot" />
 * <seealso name="CreatePlayerObject" />
 * <remarks>To smoothly rotate an object, see <a href="#MovePlayerObject">MovePlayerObject</a>.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.
 * </returns>
 */
native bool:SetPlayerObjectRot(playerid, objectid, Float:rotationX, Float:rotationY, Float:rotationZ);

/**
 * <library>omp_object</library>
 * <summary>Use this function to get the object's current rotation.  The rotation is saved by reference
 * in three rotationX/rotationY/rotationZ variables.</summary>
 * <param name="playerid">The player you associated this object to</param>
 * <param name="objectid">The objectid of the object you want to get the rotation from</param>
 * <param name="rotationX">The variable to store the x rotation, passed by reference</param>
 * <param name="rotationY">The variable to store the y rotation, passed by reference</param>
 * <param name="rotationZ">The variable to store the z rotation, passed by reference</param>
 * <seealso name="SetPlayerObjectRot" />
 * <seealso name="GetPlayerObjectPos" />
 * <seealso name="GetObjectRot" />
 * <seealso name="CreatePlayerObject" />
 * <returns>The object's rotation is stored in the specified variables.</returns>
 */
native bool:GetPlayerObjectRot(playerid, objectid, &Float:rotationX, &Float:rotationY, &Float:rotationZ);

/**
 * <library>omp_object</library>
 * <summary>Retrieve the model ID of a player-object.</summary>
 * <param name="playerid">The ID of the player whose player-object to get the model of</param>
 * <param name="objectid">The ID of the player-object of which to retrieve the model ID</param>
 * <seealso name="GetObjectModel" />
 * <seealso name="CreatePlayerObject" />
 * <returns>The model ID of the player object.  If the player or object don't exist, it will return
 * <b><c>-1</c></b> or <b><c>0</c></b> if the player or object does not exist.</returns>
 */
native GetPlayerObjectModel(playerid, objectid);

/**
 * <library>omp_object</library>
 * <summary>Toggles a player object camera collision.</summary>
 * <param name="playerid">The playerid the object belongs to</param>
 * <param name="objectid">The ID of the object you want to toggle</param>
 * <seealso name="SetObjectNoCameraCol" />
 * <seealso name="SetObjectsDefaultCameraCol" />
 * <remarks>This only works outside the map boundaries (past <b><c>-3000</c></b>/<b><c>3000</c></b>
 * units on the x and/or y axis).</remarks>
 * <returns><b><c>1</c></b> regardless of if the object exists or not.</returns>
 */
#if __namemax > 31
	native bool:SetPlayerObjectNoCameraCollision(playerid, objectid);
#endif

#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `SetPlayerObjectNoCameraCollision`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native bool:SetPlayerObjectNoCameraCol(playerid, objectid);

/**
 * <library>omp_object</library>
 * <summary>Checks if the given object ID is valid for the given player.</summary>
 * <param name="playerid">The ID of the player whose player-object to validate</param>
 * <param name="objectid">The ID of the object to validate</param>
 * <seealso name="IsValidObject" />
 * <seealso name="CreatePlayerObject" />
 * <seealso name="DestroyPlayerObject" />
 * <returns><b><c>1</c></b> if the object exists, <b><c>0</c></b> if not.</returns>
 */
native bool:IsValidPlayerObject(playerid, objectid);

/**
 * <library>omp_object</library>
 * <summary>Destroy a player-object created using <a href="#CreatePlayerObject">CreatePlayerObject</a>.</summary>
 * <param name="playerid">The ID of the player whose player-object to destroy</param>
 * <param name="objectid">The ID of the player-object to destroy.  Returned by <a href="#CreatePlayerObject">CreatePlayerObject</a></param>
 * <seealso name="CreatePlayerObject" />
 * <seealso name="IsValidPlayerObject" />
 * <seealso name="DestroyObject" />
 */
native bool:DestroyPlayerObject(playerid, objectid);

/**
 * <library>omp_object</library>
 * <summary>Move a player object with a set speed.  Also supports rotation.  Players/vehicles will surf
 * moving objects.</summary>
 * <param name="playerid">The ID of the player whose player-object to move</param>
 * <param name="objectid">The ID of the object to move</param>
 * <param name="targetX">The x coordinate to move the object to</param>
 * <param name="targetY">The y coordinate to move the object to</param>
 * <param name="targetZ">The z coordinate to move the object to</param>
 * <param name="speed">The speed at which to move the object</param>
 * <param name="rotationX">The final x rotation (optional=<b><c>-1000.0</c></b>)</param>
 * <param name="rotationY">The final y rotation (optional=<b><c>-1000.0</c></b>)</param>
 * <param name="rotationZ">The final z rotation (optional=<b><c>-1000.0</c></b>)</param>
 * <seealso name="OnPlayerObjectMoved" />
 * <seealso name="IsPlayerObjectMoving" />
 * <seealso name="StopPlayerObject" />
 * <seealso name="MoveObject" />
 * <seealso name="SetPlayerObjectPos" />
 * <seealso name="SetPlayerObjectRot" />
 * <seealso name="CreatePlayerObject" />
 * <returns>The time it will take for the object to move in milliseconds.</returns>
 */
native bool:MovePlayerObject(playerid, objectid, Float:targetX, Float:targetY, Float:targetZ, Float:speed, Float:rotationX = -1000.0, Float:rotationY = -1000.0, Float:rotationZ = -1000.0);

/**
 * <library>omp_object</library>
 * <summary>Stop a moving player-object after <a href="#MovePlayerObject">MovePlayerObject</a> has been
 * used.</summary>
 * <param name="playerid">The ID of the player whose player-object to stop</param>
 * <param name="objectid">The ID of the player-object to stop</param>
 * <seealso name="MovePlayerObject" />
 * <seealso name="IsPlayerObjectMoving" />
 * <seealso name="OnPlayerObjectMoved" />
 * <seealso name="StopObject" />
 */
native bool:StopPlayerObject(playerid, objectid);

/**
 * <library>omp_object</library>
 * <summary>Checks if the given player objectid is moving.</summary>
 * <param name="playerid">The ID of the player whose player-object is checked</param>
 * <param name="objectid">The player objectid you want to check if is moving</param>
 * <seealso name="MovePlayerObject" />
 * <seealso name="StopPlayerObject" />
 * <seealso name="OnPlayerObjectMoved" />
 * <seealso name="IsObjectMoving" />
 * <returns><b><c>1</c></b> if the player object is moving, <b><c>0</c></b> if not.</returns>
 */
native bool:IsPlayerObjectMoving(playerid, objectid);

/**
 * <library>omp_object</library>
 * <summary>Replace the texture of a player-object with the texture from another model in the game.</summary>
 * <param name="playerid">The ID of the player the object is associated to</param>
 * <param name="objectid">The ID of the object to replace the texture of</param>
 * <param name="materialIndex">The material index on the object to change (<b><c>0</c></b> to <b><c>15</c></b>)</param>
 * <param name="modelid">The modelid on which replacement texture is located.  Use <b><c>0</c></b> for
 * alpha.  Use <b><c>-1</c></b> to change the material colour without altering the existing texture</param>
 * <param name="textureLibrary">The name of the txd file which contains the replacement texture (use
 * <b><c>"none"</c></b> if not required)</param>
 * <param name="textureName">The name of the texture to use as the replacement (use <b><c>"none"</c></b>
 * if not required)</param>
 * <param name="materialColour">The object colour to set (<b>ARGB</b>).  Using <b><c>0</c></b> keeps
 * the existing material colour (optional=<b><c>0</c></b>)</param>
 * <seealso name="SetObjectMaterial" />
 * <seealso name="SetPlayerObjectMaterialText" />
 * <remarks>Vertex lightning of the object will disappear if material colour is changed.</remarks>
 */
native bool:SetPlayerObjectMaterial(playerid, objectid, materialIndex, modelid, const textureLibrary[], const textureName[], materialColour = 0);

/**
 * <library>omp_object</library>
 * <summary>Replace the texture of a player object with text.</summary>
 * <param name="playerid">The ID of the player whose player object to set the text of</param>
 * <param name="objectid">The ID of the object on which to place the text</param>
 * <param name="text">The text to set.  May be optionally formatted</param>
 * <param name="materialIndex">The material index to replace with text (optional=<b><c>0</c></b>)</param>
 * <param name="materialSize">The size of the material (optional=<b><c>OBJECT_MATERIAL_SIZE_256x128</c></b>)</param>
 * <param name="fontFace">The font to use (optional=<b><c>"Arial"</c></b>)</param>
 * <param name="fontSize">The size of the text (MAX 255) (optional=<b><c>24</c></b>)</param>
 * <param name="bold">Bold text.  Set to <b><c>1</c></b> for bold, <b><c>0</c></b> for not (optional=<b><c>1</c></b>)</param>
 * <param name="fontColour">The colour of the text (optional=<b><c>-1</c></b>)</param>
 * <param name="backgroundColour">The background colour (optional=<b><c>0</c></b>)</param>
 * <param name="textAlignment">The alignment of the text (optional=<b><c>OBJECT_MATERIAL_TEXT_ALIGN_LEFT</c></b>)</param>
 * <seealso name="SetObjectMaterialText" />
 * <seealso name="SetPlayerObjectMaterial" />
 * <remarks>Color embedding can be used for multiple colours in the text.</remarks>
 * <remarks>
 *   <b>Alignment:</b><br />
 *   <ul>
 *     <li><b><c>OBJECT_MATERIAL_TEXT_ALIGN_LEFT</c></b> 0</li>
 *     <li><b><c>OBJECT_MATERIAL_TEXT_ALIGN_CENTER</c></b> 1</li>
 *     <li><b><c>OBJECT_MATERIAL_TEXT_ALIGN_RIGHT</c></b> 2</li>
 *   </ul>
 * </remarks>
 * <remarks>
 *   <b>Sizes:</b><br />
 *   <ul>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_32x32</c></b> 10</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_64x32</c></b> 20</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_64x64</c></b> 30</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_128x32</c></b> 40</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_128x64</c></b> 50</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_128x128</c></b> 60</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_256x32</c></b> 70</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_256x64</c></b> 80</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_256x128</c></b> 90</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_256x256</c></b> 100</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_512x64</c></b> 110</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_512x128</c></b> 120</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_512x256</c></b> 130</li>
 *     <li><b><c>OBJECT_MATERIAL_SIZE_512x512</c></b> 140</li>
 *   </ul>
 * </remarks>
 */
native bool:SetPlayerObjectMaterialText(playerid, objectid, const text[], materialIndex = 0, OBJECT_MATERIAL_SIZE:materialSize = OBJECT_MATERIAL_SIZE_256x128, const fontFace[] = "Arial", fontSize = 24, bool:bold = true, fontColour = 0xFFFFFFFF, backgroundColour = 0, OBJECT_MATERIAL_TEXT_ALIGN:textAlignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT, OPEN_MP_TAGS:...);

/**
 * <library>omp_object</library>
 * <summary>Allows players to edit a player-object (position and rotation) with a GUI and their mouse.</summary>
 * <param name="playerid">The ID of the player that should edit the object</param>
 * <param name="objectid">The object to be edited by the player</param>
 * <seealso name="EditObject" />
 * <seealso name="EditAttachedObject" />
 * <seealso name="SelectObject" />
 * <seealso name="CancelEdit" />
 * <remarks>You can move the camera while editing by pressing and holding the <b>spacebar</b> (or <b>W</b>
 * in vehicle) and moving your mouse.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  Player or object not valid.
 * </returns>
 */
native bool:BeginPlayerObjectEditing(playerid, objectid);

/**
 * <library>omp_object</library>
 * <summary>Allows players to edit a player-object (position and rotation) with a GUI and their mouse.</summary>
 * <param name="playerid">The ID of the player that should edit the object</param>
 * <param name="objectid">The object to be edited by the player</param>
 * <seealso name="EditObject" />
 * <seealso name="EditAttachedObject" />
 * <seealso name="SelectObject" />
 * <seealso name="CancelEdit" />
 * <remarks>You can move the camera while editing by pressing and holding the <b>spacebar</b> (or <b>W</b>
 * in vehicle) and moving your mouse.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  Player or object not valid.
 * </returns>
 */
native bool:EditPlayerObject(playerid, objectid) = BeginPlayerObjectEditing;

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native Float:GetPlayerObjectDrawDistance(playerid, objectid);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:SetPlayerObjectMoveSpeed(playerid, objectid, Float:speed);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native Float:GetPlayerObjectMoveSpeed(playerid, objectid);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetPlayerObjectTarget(playerid, objectid, &Float:targetX = 0.0, &Float:targetY = 0.0, &Float:targetZ = 0.0) = GetPlayerObjectMovingTargetPos;

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetPlayerObjectAttachedData(playerid, objectid, &parentVehicle, &parentObject = 0, &parentPlayer = 0);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetPlayerObjectAttachedOffset(playerid, objectid, &Float:offsetX = 0.0, &Float:offsetY = 0.0, &Float:offsetZ = 0.0, &Float:rotationX = 0.0, &Float:rotationY = 0.0, &Float:rotationZ = 0.0);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetPlayerObjectSyncRotation(playerid, objectid);

/**
 * <library>omp_object</library>
 * <remarks>This is NOT a boolean return.</remarks>
 * <summary>Get the type of material slot usage.  0 - None, 1 - Material, 2 - Text.</summary>
 */
native IsPlayerObjectMaterialSlotUsed(playerid, objectid, materialIndex);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetPlayerObjectMaterial(playerid, objectid, materialIndex, &modelid, textureLibrary[], textureLibrarySize = sizeof (textureLibrary), textureName[], textureNameSize = sizeof (textureName), &materialColour = 0);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetPlayerObjectMaterialText(playerid, objectid, materialIndex, text[], textSize = sizeof (text), &OBJECT_MATERIAL_SIZE:materialSize, fontFace[], fontFaceSize = sizeof (fontFace), &fontSize = 0, &bool:bold = true, &fontColour = 0xFFFFFFFF, &backgroundColour = 0, &OBJECT_MATERIAL_TEXT_ALIGN:textAlignment = OBJECT_MATERIAL_TEXT_ALIGN_LEFT);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:IsPlayerObjectNoCameraCol(playerid, objectid);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
stock bool:HasPlayerObjectCameraCollision(playerid, objectid)
{
	return !IsPlayerObjectNoCameraCol(playerid, objectid);
}

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native GetPlayerSurfingPlayerObjectID(playerid);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetPlayerObjectMovingTargetPos(playerid, objectid, &Float:targetX, &Float:targetY, &Float:targetZ);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetPlayerObjectMovingTargetRot(playerid, objectid, &Float:rotationX, &Float:rotationY, &Float:rotationZ);

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
#if __namemax > 31
	native GetPlayerCameraTargetPlayerObject(playerid);
#endif

#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `GetPlayerCameraTargetPlayerObject`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native GetPlayerCameraTargetPlayerObj(playerid);

/*
native # Attachments();
native          Attachments(
native      ====================(
native
*/

/**
 * <library>omp_object</library>
 * <summary></summary>
 */
native bool:GetPlayerAttachedObject(playerid, index, &modelid, &bone = 0, &Float:offsetX = 0.0, &Float:offsetY = 0.0, &Float:offsetZ = 0.0, &Float:rotationX = 0.0, &Float:rotationY = 0.0, &Float:rotationZ = 0.0, &Float:scaleX = 0.0, &Float:scaleY = 0.0, &Float:scaleZ = 0.0, &materialColour1 = 0, &materialColour2 = 0);

/**
 * <library>omp_object</library>
 * <summary>Attach an object to a specific bone on a player.</summary>
 * <param name="playerid">The ID of the player to attach the object to</param>
 * <param name="index">The index (slot) to assign the object to (0-9)</param>
 * <param name="modelid">The <a href="https://dev.prineside.com/en/gtasa_samp_model_id/">model</a> to attach</param>
 * <param name="bone">The bone to attach the object to</param>
 * <param name="offsetX">x axis offset for the object position (optional=<b><c>0.0</c></b>)</param>
 * <param name="offsetY">y axis offset for the object position (optional=<b><c>0.0</c></b>)</param>
 * <param name="offsetZ">z axis offset for the object position (optional=<b><c>0.0</c></b>)</param>
 * <param name="rotationX">x axis rotation of the object (optional=<b><c>0.0</c></b>)</param>
 * <param name="rotationY">y axis rotation of the object (optional=<b><c>0.0</c></b>)</param>
 * <param name="rotationZ">z axis rotation of the object (optional=<b><c>0.0</c></b>)</param>
 * <param name="scaleX">x axis scale of the object (optional=<b><c>1.0</c></b>)</param>
 * <param name="scaleY">y axis scale of the object (optional=<b><c>1.0</c></b>)</param>
 * <param name="scaleZ">z axis scale of the object (optional=<b><c>1.0</c></b>)</param>
 * <param name="materialColour1">The first object colour to set <b>ARGB</b> (optional=<b><c>0</c></b>)</param>
 * <param name="materialColour2">The second object colour to set <b>ARGB</b> (optional=<b><c>0</c></b>)</param>
 * <seealso name="RemovePlayerAttachedObject" />
 * <seealso name="IsPlayerAttachedObjectSlotUsed" />
 * <seealso name="EditAttachedObject" />
 * <remarks>This function is separate from the <a href="#CreateObject">CreateObject</a>/
 * <a href="#CreatePlayerObject">CreatePlayerObject</a>
 * pools.</remarks>
 * <remarks>
 *   <b>Bone IDs:</b><br />
 *   <ul>
 *     <li><b><c>1</c></b> - spine</li>
 *     <li><b><c>2</c></b> - head</li>
 *     <li><b><c>3</c></b> - left upper arm</li>
 *     <li><b><c>4</c></b> - right upper arm</li>
 *     <li><b><c>5</c></b> - left hand</li>
 *     <li><b><c>6</c></b> - right hand</li>
 *     <li><b><c>7</c></b> - left thigh</li>
 *     <li><b><c>8</c></b> - right thigh</li>
 *     <li><b><c>9</c></b> - left foot</li>
 *     <li><b><c>10</c></b> - right foot</li>
 *     <li><b><c>11</c></b> - right calf</li>
 *     <li><b><c>12</c></b> - left calf</li>
 *     <li><b><c>13</c></b> - left forearm</li>
 *     <li><b><c>14</c></b> - right forearm</li>
 *     <li><b><c>15</c></b> - left clavicle (shoulder)</li>
 *     <li><b><c>16</c></b> - right clavicle (shoulder)</li>
 *     <li><b><c>17</c></b> - neck</li>
 *     <li><b><c>18</c></b> - jaw </li>
 *   </ul>
 * </remarks>
 * <returns><b><c>1</c></b> on success, <b><c>0</c></b> on failure.</returns>
 */
native bool:SetPlayerAttachedObject(playerid, index, modelid, bone, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0, Float:rotationX = 0.0, Float:rotationY = 0.0, Float:rotationZ = 0.0, Float:scaleX = 1.0, Float:scaleY = 1.0, Float:scaleZ = 1.0, materialColour1 = 0, materialColour2 = 0);

/**
 * <library>omp_object</library>
 * <summary>Remove an attached object from a player.</summary>
 * <param name="playerid">The ID of the player to remove the object from</param>
 * <param name="index">The index of the object to remove (set with <a href="#SetPlayerAttachedObject">SetPlayerAttachedObject</a>)</param>
 * <seealso name="SetPlayerAttachedObject" />
 * <seealso name="IsPlayerAttachedObjectSlotUsed" />
 * <returns><b><c>1</c></b> on success, <b><c>0</c></b> on failure.</returns>
 */
native bool:RemovePlayerAttachedObject(playerid, index);

/**
 * <library>omp_object</library>
 * <summary>Check if a player has an object attached in the specified index (slot).</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <param name="index">The index (slot) to check</param>
 * <seealso name="SetPlayerAttachedObject" />
 * <seealso name="RemovePlayerAttachedObject" />
 * <returns><b><c>1</c></b> if used, <b><c>0</c></b> if not.</returns>
 */
native bool:IsPlayerAttachedObjectSlotUsed(playerid, index);

/**
 * <library>omp_object</library>
 * <summary>Enter edition mode for an attached object.</summary>
 * <param name="playerid">The ID of the player to enter in to edition mode</param>
 * <param name="index">The index (slot) of the attached object to edit</param>
 * <seealso name="SetPlayerAttachedObject" />
 * <seealso name="RemovePlayerAttachedObject" />
 * <seealso name="IsPlayerAttachedObjectSlotUsed" />
 * <seealso name="EditObject" />
 * <seealso name="EditPlayerObject" />
 * <seealso name="SelectObject" />
 * <seealso name="CancelEdit" />
 * <seealso name="OnPlayerEditAttachedObject" />
 * <remarks>You can move the camera while editing by pressing and holding the <b>spacebar</b> (or <b>W</b>
 * in vehicle) and moving your mouse.</remarks>
 * <remarks>
 *   There are 7 clickable buttons in edition mode.<br />
 *   The three single icons that have x/y/z on them can be dragged to edit position/rotation/scale.<br
 * />
 *   The four buttons in a row are to select the edition mode and save edition: [Move] [Rotate] [Scale]
 * [Save].<br />
 *   Clicking save will call <a href="#OnPlayerEditAttachedObject">OnPlayerEditAttachedObject</a>.
 * </remarks>
 * <remarks>Players will be able to scale objects up to a very large or negative value size.  Limits
 * should be put in place using <a href="#OnPlayerEditAttachedObject">OnPlayerEditAttachedObject</a>
 * to abort the edit.</remarks>
 * <returns><b><c>1</c></b> on success and <b><c>0</c></b> on failure.</returns>
 */
native bool:EditAttachedObject(playerid, index);

/*
native # DL();
native               DL(
native      ====================(
native
*/

/**
 * <library>omp_object</library>
 */
native bool:AddCharModel(baseid, newid, const dff[], const textureLibrary[]);

/**
 * <library>omp_object</library>
 */
native bool:AddSimpleModel(virtualWorld, baseid, newid, const dff[], const textureLibrary[]);

/**
 * <library>omp_object</library>
 */
native bool:AddSimpleModelTimed(virtualWorld, baseid, newid, const dff[], const textureLibrary[], timeOn, timeOff);

/**
 * <library>omp_object</library>
 */
native FindModelFileNameFromCRC(crc, output[], size = sizeof (output));

/**
 * <library>omp_object</library>
 */
native FindTextureFileNameFromCRC(crc, output[], size = sizeof (output));

/**
 * <library>omp_object</library>
 */
native bool:RedirectDownload(playerid, const url[]);

/**
 * <library>omp_object</library>
 */
native bool:GetCustomModelPath(modelid, dffPath[], dffSize = sizeof (dffPath), txdPath[], txdSize = sizeof (txdPath));

/**
 * <library>omp_object</library>
 */
native bool:IsValidCustomModel(modelid);

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
 * <summary>This callback is called when a player selects an object after <a href="#SelectObject">SelectObject</a>
 * has been used.</summary>
 * <param name="playerid">The ID of the player that selected an object</param>
 * <param name="type">The type of selection</param>
 * <param name="objectid">The ID of the selected object</param>
 * <param name="modelid">The model ID of the selected object</param>
 * <param name="fX">The X position of the selected object</param>
 * <param name="fY">The Y position of the selected object</param>
 * <param name="fZ">The Z position of the selected object</param>
 * <seealso name="SelectObject" />
 * <returns>
 *   <b><c>1</c></b> - Will prevent other scripts from receiving this callback.<br />
 *   <b><c>0</c></b> - Indicates that this callback will be passed to the next script.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
#if !defined SELECT_OBJECT
	#define SELECT_OBJECT: _:
#endif
forward OnPlayerSelectObject(playerid, SELECT_OBJECT:type, objectid, modelid, Float:fX, Float:fY, Float:fZ);

/**
 * <summary>This callback is called when a player finishes editing an object (<a href="#EditObject">EditObject</a>/<a
 * href="#EditPlayerObject">EditPlayerObject</a>).</summary>
 * <param name="playerid">The ID of the player that edited an object</param>
 * <param name="playerobject"><b><c>0</c></b> if it is a global object or <b><c>1</c></b> if it is a
 * playerobject</param>
 * <param name="objectid">The ID of the edited object</param>
 * <param name="response">The type of response</param>
 * <param name="fX">The X offset for the object that was edited</param>
 * <param name="fY">The Y offset for the object that was edited</param>
 * <param name="fZ">The Z offset for the object that was edited</param>
 * <param name="rotationX">The X rotation for the object that was edited</param>
 * <param name="rotationY">The Y rotation for the object that was edited</param>
 * <param name="rotationZ">The Z rotation for the object that was edited</param>
 * <seealso name="EditObject" />
 * <seealso name="CreateObject" />
 * <seealso name="DestroyObject" />
 * <seealso name="MoveObject" />
 * <remarks>When using <b><c>EDIT_RESPONSE_UPDATE</c></b> be aware that this callback will not be called
 * when releasing an edit in progress resulting in the last update of <b><c>EDIT_RESPONSE_UPDATE</c></b>
 * being out of sync of the objects current position.</remarks>
 * <returns>
 *   <b><c>1</c></b> - Will prevent other scripts from receiving this callback.<br />
 *   <b><c>0</c></b> - Indicates that this callback will be passed to the next script.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerEditObject(playerid, playerobject, objectid, EDIT_RESPONSE:response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ);

/**
 * <summary>This callback is called when a player ends attached object edition mode.</summary>
 * <param name="playerid">The ID of the player that ended edition mode</param>
 * <param name="response"><b><c>0</c></b> if they cancelled (ESC) or <b><c>1</c></b> if they clicked
 * the save icon</param>
 * <param name="index">The index of the attached object</param>
 * <param name="modelid">The model of the attached object that was edited</param>
 * <param name="boneid">The bone of the attached object that was edited</param>
 * <param name="fOffsetX">The X offset for the attached object that was edited</param>
 * <param name="fOffsetY">The Y offset for the attached object that was edited</param>
 * <param name="fOffsetZ">The Z offset for the attached object that was edited</param>
 * <param name="rotationX">The X rotation for the attached object that was edited</param>
 * <param name="rotationY">The Y rotation for the attached object that was edited</param>
 * <param name="rotationZ">The Z rotation for the attached object that was edited</param>
 * <param name="scaleX">The X scale for the attached object that was edited</param>
 * <param name="scaleY">The Y scale for the attached object that was edited</param>
 * <param name="scaleZ">The Z scale for the attached object that was edited</param>
 * <seealso name="EditAttachedObject" />
 * <seealso name="SetPlayerAttachedObject" />
 * <remarks>Editions should be discarded if response was <b><c>0</c></b> (cancelled).  This must be
 * done by storing the offsets etc.  in an array BEFORE using <a href="#EditAttachedObject">EditAttachedObject</a>.</remarks>
 * <returns>
 *   <b><c>1</c></b> - Will prevent other scripts from receiving this callback.<br />
 *   <b><c>0</c></b> - Indicates that this callback will be passed to the next script.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerEditAttachedObject(playerid, EDIT_RESPONSE:response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ);

/**
 * <summary>This callback is called when an object is moved after <a href="#MoveObject">MoveObject</a>
 * (when it stops moving).</summary>
 * <param name="objectid">The ID of the object that was moved</param>
 * <seealso name="MoveObject" />
 * <seealso name="IsObjectMoving" />
 * <seealso name="StopObject" />
 * <seealso name="OnPlayerObjectMoved" />
 * <remarks><a href="#SetObjectPos">SetObjectPos</a> does not work when used in this callback.  To fix
 * it, recreate the object.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnObjectMoved(objectid);

/**
 * <summary>This callback is called when a player object is moved after <a href="#MovePlayerObject">MovePlayerObject</a>
 * (when it stops moving).</summary>
 * <param name="playerid">The playerid the object is assigned to</param>
 * <param name="objectid">The ID of the player object that was moved</param>
 * <seealso name="OnObjectMoved" />
 * <seealso name="MovePlayerObject" />
 * <seealso name="IsPlayerObjectMoving" />
 * <seealso name="StopPlayerObject" />
 * <remarks>This callback can also be called for NPC.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerObjectMoved(playerid, objectid);
