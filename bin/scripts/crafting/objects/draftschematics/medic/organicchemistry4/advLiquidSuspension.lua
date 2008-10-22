--Copyright (C) 2008 <SWGEmu>


--This File is part of Core3.

--This program is free software; you can redistribute 
--it and/or modify it under the terms of the GNU Lesser 
--General Public License as published by the Free Software
--Foundation; either version 2 of the License, 
--or (at your option) any later version.

--This program is distributed in the hope that it will be useful, 
--but WITHOUT ANY WARRANTY; without even the implied warranty of 
--MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
--See the GNU Lesser General Public License for
--more details.

--You should have received a copy of the GNU Lesser General 
--Public License along with this program; if not, write to
--the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

--Linking Engine3 statically or dynamically with other modules 
--is making a combined work based on Engine3. 
--Thus, the terms and conditions of the GNU Lesser General Public License 
--cover the whole combination.

--In addition, as a special exception, the copyright holders of Engine3 
--give you permission to combine Engine3 program with free software 
--programs or libraries that are released under the GNU LGPL and with 
--code included in the standard release of Core3 under the GNU LGPL 
--license (or modified versions of such code, with unchanged license). 
--You may copy and distribute such a system following the terms of the 
--GNU LGPL for Engine3 and the licenses of the other code concerned, 
--provided that you include the source code of that other code when 
--and as the GNU LGPL requires distribution of source code.

--Note that people who make modified versions of Engine3 are not obligated 
--to grant this special exception for their modified versions; 
--it is their choice whether to do so. The GNU Lesser General Public License 
--gives permission to release a modified version without this exception; 
--this exception also makes it possible to release a modified version 
--which carries forward this exception.
advLiquidSuspension = Object:new {

   objectName = "Adv Liquid Suspension", -- name of the lua Object
   stfName = "liquid_suspension_advanced", 
   objectCRC = 3383554373, 
   groupName = "craftMedicineComponentGroupD", 

   craftingToolTab = 64, 
   complexity = 18, 
   size = 2, 

   xpType = "crafting_medicine_general", 
   xp = 35, 

   assemblySkill = "medicine_assembly", 
   experimentingSkill = "medicine_experimentation", 

   ingredientTemplateNames = "craft_chemical_ingredients_n, craft_chemical_ingredients_n",
   ingredientTitleNames = "purified_organic_suspension, suspension_base",
   ingredientOptionals = "0, 0",
   resourceTypes = "fruit_berries_dantooine, water_vapor_talus",
   resourceQuantities = "6, 6",
   combineTypes = "1, 1",
   contribution = "100, 100",

   numberExperimentalProperties = "1, 2",
   experimentalProperties = "XX, OQ, PE",
   experimentalWeights = "0, 1, 2",
   experimentalGroupTitles = "exp_durability, exp_effectiveness",
   experimentalSubGroupCount = "1",
   experimentalSubGroupTitles = "power",

   tanoAttributes = "objecttype=262144:objectcrc=1862978449:objecttemp=liquid_suspension_advanced:templatetype=craft_chemical_ingredients_n:",


   attributesToSet = "power",
   attributeExperimentalProperties = "exp_effectiveness",
   attributePrecision = "0",
   attributesMinMax = "50, 200"

}

DraftSchematics:addDraftSchematic(advLiquidSuspension, 3383554373)--- Add to global DraftSchematics table
