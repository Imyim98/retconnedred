MagicWorld_Center_Winter_MapScripts::
	.byte 0

Magic_World_Center_Winter_Sign1::
	lock
	setflag FLAG_MUSIC_NO_CHANGE
	additem ITEM_DYNAMAX_BAND
	additem ITEM_TERA_ORB
	additem ITEM_Z_POWER_RING
	additem ITEM_MEGA_RING
	setflag FLAG_TERA_ORB_CHARGED
	setflag FLAG_TERA_ORB_NO_COST
	release
	end
