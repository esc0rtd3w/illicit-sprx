#ifndef __PARTICLEFX_H
#define __PARTICLEFX_H

#include "addresses.h"
#include "core.h"
#include "types.h"

using namespace Addresses;


namespace ParticleFX
{
	//opd_s _START_PARTICLE_FX_LOOPED_ON_ENTITY = { Addresses::Addresses_Natives::Entity_a::START_PARTICLE_FX_LOOPED_ON_ENTITY, TOC };
	//Any(*START_PARTICLE_FX_LOOPED_ON_ENTITY)(char* effectName, Entity entity, float xOffset, float yOffset, float zOffset, float xRot, float yRot, float zRot, float scale, BOOL p9, BOOL p10, BOOL p11) = (Any(*)(char*, Entity, float, float, float, float, float, float, float, BOOL, BOOL, BOOL))&_START_PARTICLE_FX_LOOPED_ON_ENTITY;

	//opd_s _START_PARTICLE_FX_LOOPED_AT_COORD = { Addresses::Addresses_Natives::Entity_a::START_PARTICLE_FX_LOOPED_AT_COORD, TOC };
	//Any(*START_PARTICLE_FX_LOOPED_AT_COORD)(char* effectName, float x, float y, float z, float xRot, float yRot, float zRot, float scale, BOOL p8, BOOL p9, BOOL p10, BOOL p11) = (Any(*)(char*, float, float, float, float, float, float, float, BOOL, BOOL, BOOL, BOOL))&_START_PARTICLE_FX_LOOPED_AT_COORD;
};



/*
START_PARTICLE_FX_LOOPED_ON_ENTITY(ParticleName, EntityID, offset X, offset Y, offset Z, Rot X, Rot Y, Rot Z, 0x3F800000, 0, 0, 0)


------------------------------------------------------------
ParticleNames

scr_trev1_crash_dust
scr_trev1_trailer_wires
scr_trev1_trailer_boosh
scr_trev1_wheelspin_dirt
ent_ray_meth_dust_settle
scr_trev1_trailer_splash
scr_paleto_banknotes
scr_paleto_roof_impact
scr_paleto_heli_plume
scr_paleto_doorway_smoke
cs_paleto_blowtorch
scr_crate_drop_flare
scr_bigscore_ramp_sparks
scr_bigscore_tyre_spiked
scr_jew_biKe_burnout
scr_jewel_cab_smash
scr_property_leaflet_drop
scr_pro_door_snow
scr_prologue_ceiling_debris
scr_prologue_vault_haze
scr_sparking_generator
scr_reconstruct_pipefall_debris
scr_trev4_747_engine_damage
scr_trev4_747_blood_impact
scr_trev4_747_exhaust_plane_misfire
scr_trev4_747_engine_heathaze
scr_trev4_trailer_fire
scr_golf_ball_trail
scr_golf_landing_water
SCR_TREV_PUKE

*/



#endif


