courier_quest_karrek = Creature:new {
	objectName = "@mob/creature_names:info_broker",
	socialGroup = "poacher",
	faction = "",
	level = 16,
	chanceHit = 0.310000,
	damageMin = 160,
	damageMax = 170,
	baseXp = 1102,
	baseHAM = 2900,
	baseHAMmax = 3500,
	armor = 0,
	resists = {0,0,0,0,0,0,0,0,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.000000,
	ferocity = 0,
	pvpBitmask = NONE,
	creatureBitmask = PACK,
	optionsBitmask = AIENABLED + CONVERSABLE,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_criminal_smuggler_human_female_01.iff"},
	lootGroups = {},
	conversationTemplate = "viceprex_tasks_mission_target_convotemplate",
	weapons = {},
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(courier_quest_karrek, "courier_quest_karrek")
