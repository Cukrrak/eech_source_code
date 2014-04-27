/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef META_EXPLOSION_DECLARATION
#define META_EXPLOSION_DECLARATION(x) x
#define META_EXPLOSION(x) x,
#define META_EXPLOSION_(x) x
#endif

META_EXPLOSION_DECLARATION(typedef enum META_EXPLOSION_TYPES)
META_EXPLOSION_DECLARATION({)
	META_EXPLOSION(META_EXPLOSION_TYPE_NONE)

	// MISC

	META_EXPLOSION(TEST_META_EXPLOSION)
	META_EXPLOSION(PURPLE_FLARE_META_EXPLOSION)

	// WEAPON EXPLOSIONS

	META_EXPLOSION(XSMALL_HE_META_EXPLOSION)
	META_EXPLOSION(SMALL_HE_META_EXPLOSION)
	META_EXPLOSION(MEDIUM_HE_META_EXPLOSION)
	META_EXPLOSION(LARGE_HE_META_EXPLOSION)
	META_EXPLOSION(XLARGE_HE_META_EXPLOSION)

	// OBJECT EXPLOSIONS

	META_EXPLOSION(SMALL_DUST_META_EXPLOSION)
	META_EXPLOSION(MEDIUM_DUST_META_EXPLOSION)
	META_EXPLOSION(LARGE_DUST_META_EXPLOSION)

	META_EXPLOSION(SMALL_EXPLOSIVE_OBJECT_META_EXPLOSION)
	META_EXPLOSION(MEDIUM_EXPLOSIVE_OBJECT_META_EXPLOSION)
	META_EXPLOSION(LARGE_EXPLOSIVE_OBJECT_META_EXPLOSION)

	// COLLISION EFFECTS

	META_EXPLOSION(SMALL_OBJECT_META_EXPLOSION)
	META_EXPLOSION(MEDIUM_OBJECT_META_EXPLOSION)
	META_EXPLOSION(LARGE_OBJECT_META_EXPLOSION)

	META_EXPLOSION(XSMALL_GROUND_META_EXPLOSION)
	META_EXPLOSION(SMALL_GROUND_META_EXPLOSION)
	META_EXPLOSION(MEDIUM_GROUND_META_EXPLOSION)
	META_EXPLOSION(LARGE_GROUND_META_EXPLOSION)
	META_EXPLOSION(XLARGE_GROUND_META_EXPLOSION)

	META_EXPLOSION(SMALL_WATER_META_EXPLOSION)
	META_EXPLOSION(MEDIUM_WATER_META_EXPLOSION)
	META_EXPLOSION(LARGE_WATER_META_EXPLOSION)

	//

	META_EXPLOSION_(NUM_META_EXPLOSION_TYPES)

META_EXPLOSION_DECLARATION(} meta_explosion_types;)

#undef META_EXPLOSION_DECLARATION
#undef META_EXPLOSION
#undef META_EXPLOSION_

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
