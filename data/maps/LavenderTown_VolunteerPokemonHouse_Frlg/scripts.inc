LavenderTown_VolunteerPokemonHouse_Frlg_MapScripts::
	.byte 0

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POKE_FLUTE, LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute
	msgbox LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis
	checkitemspace ITEM_POKE_FLUTE
	goto_if_eq VAR_RESULT, FALSE, LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute
	setflag FLAG_GOT_POKE_FLUTE
	giveitem_msg LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji, ITEM_POKE_FLUTE, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute
	waitse
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MegaRing
	giveitem_msg LavenderTown_VolunteerPokemonHouse_Text_ReceivedMegaRing, ITEM_MEGA_RING, 1, MUS_RG_OBTAIN_KEY_ITEM
	switch VAR_STARTER_MON
	case 0, LavenderTown_EventScript_Venusaur
	case 1, LavenderTown_EventScript_Blastoise
	case 2, LavenderTown_EventScript_Charizard
	release
	end

LavenderTown_EventScript_Venusaur::
	giveitem_msg Text_ReceivedVenusaurite, ITEM_VENUSAURITE, 1, MUS_RG_OBTAIN_KEY_ITEM
	end

LavenderTown_EventScript_Charizard::
	giveitem_msg Text_ReceivedCharizarditeY, ITEM_CHARIZARDITE_Y, 1, MUS_RG_OBTAIN_KEY_ITEM
	end

LavenderTown_EventScript_Blastoise::
	giveitem_msg Text_ReceivedBlastoisinite, ITEM_BLASTOISINITE, 1, MUS_RG_OBTAIN_KEY_ITEM
	end

LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
	lock
	faceplayer
	famechecker FAMECHECKER_MRFUJI, 0
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack
	msgbox LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Nidorino
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Psyduck
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
	lockall
	famechecker FAMECHECKER_MRFUJI, 2
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped
	releaseall
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf, MSGBOX_SIGN
	end

LavenderTown_PokemonCenter_1F_Text_HearMrFujiNotFromAroundHere::
	.string "I recently moved to this town.\p"
	.string "I hear that MR. FUJI's not from\n"
	.string "these parts originally, either.$"

LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo::
	.string "That's odd, MR. FUJI isn't here.\n"
	.string "Where'd he go?$"

LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother::
	.string "MR. FUJI had been praying alone\n"
	.string "for CUBONE's mother.$"

LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons::
	.string "This is really MR. FUJI's house.\p"
	.string "He's really kind.\p"
	.string "He looks after abandoned and\n"
	.string "orphaned POKéMON.$"

LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug::
	.string "It's so warm!\n"
	.string "POKéMON are so nice to hug.$"

LavenderTown_VolunteerPokemonHouse_Text_Nidorino::
	.string "NIDORINO: Gaoo!$"

LavenderTown_VolunteerPokemonHouse_Text_Psyduck::
	.string "PSYDUCK: Gwappa!$"

LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis::
	.string "MR. FUJI: First of all,\p"
	.string "I would like to thank you for\n"
	.string "coming to aid MAROWAK's spirit.\p"
	.string "Please take this.$"

LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji::
	.string "{PLAYER} received a POKé FLUTE\n"
	.string "from MR. FUJI.$"

LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute::
	.string "Upon hearing the POKé FLUTE,\n"
	.string "sleeping POKéMON will spring awake.\p"
	.string "Try using it on POKéMON that are\n"
	.string "sleeping obstacles.$"

LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis::
	.string "You must make room for this!$"

LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou::
	.string "MR. FUJI: Have my gifts\n"
	.string "helped you?$"

LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped::
	.string "POKéMON FAN MAGAZINE\n"
	.string "Monthly Grand Prize Drawing!\p"
	.string "The application form is…\p"
	.string "Gone! It's been clipped out.\n"
	.string "Someone must have applied already.$"

LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf::
	.string "POKéMON magazines line the shelf.\p"
	.string "POKéMON INSIDER…\p"
	.string "POKéMON FAN…$"

LavenderTown_VolunteerPokemonHouse_Text_MegaRing::
	.string "MR. FUJI: {PLAYER}…\p"
	.string "Your POKéDEX quest is one that\n"
	.string "requires strong dedication.\p"
	.string "Without deep love for POKéMON,\n"
	.string "your quest may fail.\p"
	.string "I believe the CHIMECHO you faced,\n"
	.string "in the tower is just the first of\n"
	.string "many such rogue MEGA POKéMON.\p"
	.string "I'm not sure if this will help you,\n"
	.string "but I'd like you to have it as well.$"

LavenderTown_VolunteerPokemonHouse_Text_ReceivedMegaRing::
	.string "{PLAYER} received a MEGA RING\n"
	.string "from MR. FUJI.$"

Text_ReceivedVenusaurite::
	.string "{PLAYER} received the VENUSAURITE!$"

Text_ReceivedCharizarditeY::
	.string "{PLAYER} received the CHARIZARDITE Y!$"

Text_ReceivedBlastoisinite::
	.string "{PLAYER} received the BLASTOISINITE!$"
