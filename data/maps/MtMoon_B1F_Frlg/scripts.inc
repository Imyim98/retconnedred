MtMoon_B1F_Frlg_MapScripts::
	.byte 0

MtMoon_B1F_EventScript_Alexandria::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXANDRIA, MtMoon_B1F_Text_AlexandriaIntro, MtMoon_B1F_Text_AlexandriaDefeat
	msgbox MtMoon_B1F_Text_AlexandriaPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B1F_Text_AlexandriaIntro::
	.string "My goal is to find the ultimate Clefable!$"

MtMoon_B1F_Text_AlexandriaDefeat::
	.string "That strength is the real deal!$"

MtMoon_B1F_Text_AlexandriaPostBattle::
	.string "I don't think I deserve to be called a\n$"
	.string "Clefable master yet!$"