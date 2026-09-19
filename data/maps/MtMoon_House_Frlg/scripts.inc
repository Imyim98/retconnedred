MtMoon_House_Frlg_MapScripts::
	.byte 0

MtMoon_House_EventScript_Clerk::
	lock
	faceplayer
	message MtMoon_House_Text_OpenShop
	waitmessage
	pokemart MtMoon_House_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
MtMoon_House_Items::
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_SODA_POP
	.2byte ITEM_LEMONADE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

MtMoon_House_Text_OpenShop::
	.string "You must be tired from climbing.\n"
	.string "How about stocking up on supplies?$"
