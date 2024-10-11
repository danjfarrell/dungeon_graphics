#include "spells.h"
//#include "player.h"
//#include "gamemap.h"
//#include "build_level.h"
//#include "ui_display.h"
//#include "monsters.h"
#include "core_engine.h"


Spells::Spells()
{

/*
	spell data
 */
//u_char          spelknow[SPNUM] = { 0 };
//u_char          splev[] = { 1, 4, 9, 14, 18, 22, 26, 29, 32, 35, 37, 37, 37, 37, 37 };
	strncpy_s(casting_spell, "", 3);
	spell_index = -1;
	char_pos = 0;
	spell_description_displayed = false;
	

	strncpy_s(spellcode[0], "pro", 3);
	strncpy_s(spellcode[1], "mle", 3);
	strncpy_s(spellcode[2], "dex", 3);
	strncpy_s(spellcode[3], "sle", 3);
	strncpy_s(spellcode[4], "chm", 3);
	strncpy_s(spellcode[5], "ssp", 3);

	strncpy_s(spellcode[6], "web", 3);
	strncpy_s(spellcode[7], "str", 3);
	strncpy_s(spellcode[8], "enl", 3);
	strncpy_s(spellcode[9], "hel", 3);
	strncpy_s(spellcode[10], "cbl", 3);
	strncpy_s(spellcode[11], "cre", 3);
	strncpy_s(spellcode[12], "pha", 3);
	strncpy_s(spellcode[13], "inv", 3);

	strncpy_s(spellcode[14], "bal", 3);
	strncpy_s(spellcode[15], "cld", 3);
	strncpy_s(spellcode[16], "ply", 3);
	strncpy_s(spellcode[17], "can", 3);
	strncpy_s(spellcode[18], "has", 3);
	strncpy_s(spellcode[19], "ckl", 3);
	strncpy_s(spellcode[20], "vpr", 3);

	strncpy_s(spellcode[21], "dry", 3);
	strncpy_s(spellcode[22], "lit", 3);
	strncpy_s(spellcode[23], "drl", 3);
	strncpy_s(spellcode[24], "glo", 3);
	strncpy_s(spellcode[25], "flo", 3);
	strncpy_s(spellcode[26], "fgr", 3);

	strncpy_s(spellcode[27], "sca", 3);
	strncpy_s(spellcode[28], "hld", 3);
	strncpy_s(spellcode[29], "stp", 3);
	strncpy_s(spellcode[30], "tel", 3);
	strncpy_s(spellcode[31], "mfi", 3);

	strncpy_s(spellcode[32], "sph", 3);
	strncpy_s(spellcode[33], "gen", 3);
	strncpy_s(spellcode[34], "sum", 3);
	strncpy_s(spellcode[35], "wtw", 3);
	strncpy_s(spellcode[36], "alt", 3);
	strncpy_s(spellcode[37], "per", 3);
	
	//spell names
	strncpy_s(spellname[0], "protection", 23);
	strncpy_s(spellname[1], "magic missile", 23);
	strncpy_s(spellname[2], "dexterity", 23);
	strncpy_s(spellname[3], "sleep", 23);
	strncpy_s(spellname[4], "charm monster", 23);
	strncpy_s(spellname[5], "sonic spear", 23);

	strncpy_s(spellname[6], "web", 23);
	strncpy_s(spellname[7], "strength", 23);
	strncpy_s(spellname[8], "enlightenment", 23);
	strncpy_s(spellname[9], "healing", 23);
	strncpy_s(spellname[10], "cure blindness", 23);
	strncpy_s(spellname[11], "create monster", 23);
	strncpy_s(spellname[12], "phantasmal forces", 23);
	strncpy_s(spellname[13], "invisibility", 23);

	strncpy_s(spellname[14], "fireball", 23);
	strncpy_s(spellname[15], "cold", 23);
	strncpy_s(spellname[16], "polymorph", 23);
	strncpy_s(spellname[17], "cancellation", 23);
	strncpy_s(spellname[18], "haste self", 23);
	strncpy_s(spellname[19], "cloud kill", 23);
	strncpy_s(spellname[20], "vaporize rock", 23);

	strncpy_s(spellname[21], "dehydration", 23);
	strncpy_s(spellname[22], "lightning", 23);
	strncpy_s(spellname[23], "drain life", 23);
	strncpy_s(spellname[24], "invulnerability", 23);
	strncpy_s(spellname[25], "flood", 23);
	strncpy_s(spellname[26], "finger of death", 23);

	strncpy_s(spellname[27], "scare monster", 23);
	strncpy_s(spellname[28], "hold monster", 23);
	strncpy_s(spellname[29], "time stop", 23);
	strncpy_s(spellname[30], "teleport away", 23);
	strncpy_s(spellname[31], "magic fire", 23);

	strncpy_s(spellname[32], "sphere of annihilation", 23);
	strncpy_s(spellname[33], "genocide", 23);
	strncpy_s(spellname[34], "summon demon", 23);
	strncpy_s(spellname[35], "walk through walls", 23);
	strncpy_s(spellname[36], "alter reality", 23);
	strncpy_s(spellname[37], "permanence", 23);


//spell description

	strncpy_s(speldescript[0], "generates a +2 protection field", 32);
	strncpy_s(speldescript[1], "creates and hurls a magic missile equivalent to a +1 magic arrow", 65);
	strncpy_s(speldescript[2], "adds +2 to the caster's dexterity", 34);
	strncpy_s(speldescript[3], "causes some monsters to go to sleep", 36);
	strncpy_s(speldescript[4], "some monsters may be awed at your magnificence", 47);
	strncpy_s(speldescript[5], "causes your hands to emit a screeching sound toward what they point", 68);
	strncpy_s(speldescript[6], "causes strands of sticky thread to entangle an enemy", 53);
	strncpy_s(speldescript[7], "adds +2 to the caster's strength for a short term", 50);
	strncpy_s(speldescript[8], "the caster becomes aware of things in the vicinity", 51);
	strncpy_s(speldescript[9], "restores some hp to the caster", 31);
	strncpy_s(speldescript[10], "restores sight to one so unfortunate as to be blinded", 54);
	strncpy_s(speldescript[11], "creates a monster near the caster appropriate for the location", 63);
	strncpy_s(speldescript[12], "creates illusions, and if believed, monsters die", 49);
	strncpy_s(speldescript[13], "the caster becomes invisible", 29);
	strncpy_s(speldescript[14], "makes a ball of fire that burns on what it hits", 48);
	strncpy_s(speldescript[15], "sends forth a cone of cold which freezes what it touches", 57);
	strncpy_s(speldescript[16], "you can find out what this does for yourself", 45);
	strncpy_s(speldescript[17], "negates the ability of a monster to use its special abilities", 62);
	strncpy_s(speldescript[18], "speeds up the caster's movements", 33);
	strncpy_s(speldescript[19], "creates a fog of poisonous gas which kills all that is within it", 65);
	strncpy_s(speldescript[20], "this changes rock to air", 25);
	strncpy_s(speldescript[21], "dries up water in the immediate vicinity", 41);
	strncpy_s(speldescript[22], "your finger will emit a lightning bolt when this spell is cast", 63);
	strncpy_s(speldescript[23], "subtracts hit points from both you and a monster", 49);
	strncpy_s(speldescript[24], "this globe helps to protect the player from physical attack", 60);
	strncpy_s(speldescript[25], "this creates an avalanche of H2O to flood the immediate chamber", 64);
	strncpy_s(speldescript[26], "this is a holy spell and calls upon your god to back you up", 60);
	strncpy_s(speldescript[27], "terrifies the monster so that hopefully it won't hit the magic user", 68);
	strncpy_s(speldescript[28], "the monster is frozen in its tracks if this is successful", 58);
	strncpy_s(speldescript[29], "all movement in the caverns ceases for a limited duration", 58);
	strncpy_s(speldescript[30], "moves a particular monster around in the dungeon (hopefully away from you)", 75);
	strncpy_s(speldescript[31], "this causes a curtain of fire to appear all around you", 55);
	strncpy_s(speldescript[32], "anything caught in this sphere is instantly killed.  Warning -- dangerous", 74);
	strncpy_s(speldescript[33], "eliminates a species of monster from the game -- use sparingly", 63);
	strncpy_s(speldescript[34], "summons a demon who hopefully helps you out", 44);
	strncpy_s(speldescript[35], "allows the player to walk through walls for a short period of time", 67);
	strncpy_s(speldescript[36], "god only knows what this will do", 33);
	strncpy_s(speldescript[37], "makes a character spell permanent, i. e. protection, strength, etc.", 68);
	strncpy_s(speldescript[38], "u suck no spell", 68);

	static int spelweird_cpy[MAXMONST + 8][NUM_SPELLS] = {
		/*                      p m d s c s    w s e h c c p i    b c p c h c v    d l d g f f    s h s t m    s g s w a p */
		/*                      r l e l h s    e t n e b r h n    a l l a a k p    r i r l l g    c l t e f    p e u t l e */
		/*                      o e x e m p    b r l l l e a v    l d y n s l r    y t l o o r    a d p l i    h n m w t r */


		/*            bat */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*          gnome */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,5,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*      hobgoblin */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*         jackal */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*         kobold */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,5,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },

		/*            orc */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   4,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*          snake */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*giant centipede */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*         jaculi */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*     troglodyte */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },

		/*      giant ant */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*   floating eye */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*     leprechaun */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*          nymph */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*         quasit */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },

		/*   rust monster */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   4,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*         zombie */ {  0,0,0,8,0,4,   0,0,0,0,0,0,0,0,   0,0,0,0,0,4,0,   4,0,0,0,0,4,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*   assassin bug */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*        bugbear */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,5,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*     hell hound */ {  0,6,0,0,0,0,   12,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },

		/*     ice lizard */ {  0,0,0,0,0,0,   11,0,0,0,0,0,0,0,  0,15,0,0,0,0,0,  0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*        centaur */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*          troll */ {  0,7,0,0,0,0,   0,0,0,0,0,0,0,5,   0,0,0,0,0,0,0,   4,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*           yeti */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,15,0,0,0,0,0,  0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*   white dragon */ {  0,0,0,0,0,0,   0,0,0,0,0,0,14,0,  0,15,0,0,0,0,0,  4,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },

		/*            elf */ {  0,0,0,0,0,0,   0,0,0,0,0,0,14,5,  0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*gelatinous cube */ {  0,0,0,0,0,0,   2,0,0,0,0,0,0,0,   0,0,0,0,0,4,0,   0,0,0,0,0,4,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*      metamorph */ {  0,13,0,0,0,0,  2,0,0,0,0,0,0,0,   0,0,0,0,0,4,0,   4,0,0,0,0,4,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*         vortex */ {  0,13,0,0,0,10, 1,0,0,0,0,0,0,0,   0,0,0,0,0,4,0,   4,0,0,0,4,4,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*         ziller */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },

		/*   violet fungi */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*         wraith */ {  0,0,0,8,0,4,   0,0,0,0,0,0,0,0,   0,0,0,0,0,4,0,   4,0,0,0,0,4,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*      forvalaka */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,5,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*      lama nobe */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*        osequip */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },

		/*          rothe */ {  0,7,0,0,0,0,   0,0,0,0,0,0,0,5,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*           xorn */ {  0,7,0,0,0,0,   0,0,0,0,0,0,0,5,   0,0,0,0,0,0,0,   4,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*        vampire */ {  0,0,0,8,0,4,   0,0,0,0,0,0,0,0,   0,0,0,0,0,4,0,   0,0,0,0,0,4,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*invisible staker*/ {  0,0,0,0,0,0,   1,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*    poltergeist */ {  0,13,0,8,0,4,  1,0,0,0,0,0,0,0,   0,4,0,0,0,4,0,   4,0,0,0,4,4,   0,0,0,0,0,   0,0,0,0,0,0 },

		/* disenchantress */ {  0,0,0,8,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*shambling mound */ {  0,0,0,0,0,10,  0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*    yellow mold */ {  0,0,0,8,0,0,   1,0,0,0,0,0,4,0,   0,0,0,0,0,4,0,   0,0,0,0,0,4,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*     umber hulk */ {  0,7,0,0,0,0,   0,0,0,0,0,0,0,5,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*     gnome king */ {  0,7,0,0,3,0,   0,0,0,0,0,0,0,5,   0,0,9,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },

		/*          mimic */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*     water lord */ {  0,13,0,8,3,4,  1,0,0,0,0,0,0,0,   0,0,9,0,0,4,0,   0,0,0,0,16,4,  0,0,0,0,0,   0,0,0,0,0,0 },
		/*  bronze dragon */ {  0,7,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*   green dragon */ {  0,7,0,0,0,0,   11,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*    purple worm */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },

		/*          xvart */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*    spirit naga */ {  0,13,0,8,3,4,  1,0,0,0,0,0,0,5,   0,4,9,0,0,4,0,   4,0,0,0,4,4,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*  silver dragon */ {  0,6,0,9,0,0,   12,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*platinum dragon */ {  0,7,0,9,0,0,   11,0,0,0,0,0,14,0, 0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*   green urchin */ {  0,0,0,0,0,0,   0,0,0,0,0,0,0,0,   0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },
		/*     red dragon */ {  0,6,0,0,0,0,   12,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,   0,0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,0 },

		/*                      p m d s c s    w s e h c c p i    b c p c h c v    d l d g f f    s h s t m    s g s w a p */
		/*                      r l e l h s    e t n e b r h n    a l l a a k p    r i r l l g    c l t e f    p e u t l e */
		/*                      o e x e m p    b r l l l e a v    l d y n s l r    y t l o o r    a d p l i    h n m w t r */

		/*     demon lord */ {  0,7,0,4,3,0,   1,0,0,0,0,0,14,5,  0,0,4,0,0,4,0,   4,0,0,0,4,4,   0,0,0,0,0,   9,0,0,0,0,0 },
		/*     demon lord */ {  0,7,0,4,3,0,   1,0,0,0,0,0,14,5,  0,0,4,0,0,4,0,   4,0,0,0,4,4,   0,0,0,0,0,   9,0,0,0,0,0 },
		/*     demon lord */ {  0,7,0,4,3,0,   1,0,0,0,0,0,14,5,  0,0,4,0,0,4,0,   4,0,0,0,4,4,   0,0,0,0,0,   9,0,0,0,0,0 },
		/*     demon lord */ {  0,7,0,4,3,0,   1,0,0,0,0,0,14,5,  0,0,4,0,0,4,0,   4,0,0,0,4,4,   0,0,0,0,0,   9,0,0,0,0,0 },
		/*     demon lord */ {  0,7,0,4,3,0,   1,0,0,0,0,0,14,5,  0,0,4,0,0,4,0,   4,0,0,0,4,4,   0,0,0,0,0,   9,0,0,0,0,0 },
		/*     demon lord */ {  0,7,0,4,3,0,   1,0,0,0,0,0,14,5,  0,0,4,0,0,4,0,   4,0,0,0,4,4,   0,0,0,0,0,   9,0,0,0,0,0 },
		/*     demon lord */ {  0,7,0,4,3,0,   1,0,0,0,0,0,14,5,  0,0,4,0,0,4,0,   4,0,0,0,4,4,   0,0,0,0,0,   9,0,0,0,0,0 },
		/*   demon prince */ {  0,7,0,4,3,9,   1,0,0,0,0,0,14,5,  0,0,4,0,0,4,0,   4,0,0,0,4,4,   4,0,0,0,4,   9,0,0,0,0,0 }

	};




	memcpy_s(spelweird, sizeof(spelweird_cpy), spelweird_cpy, sizeof(spelweird_cpy));

	strncpy_s(spelmes[0], "", 68);
	strncpy_s(spelmes[1], "the web had no effect on the %s", 68);
	strncpy_s(spelmes[2], "the %s changed shape to avoid the web", 68);
	strncpy_s(spelmes[3], "the %s isn't afraid of you", 68);
	strncpy_s(spelmes[4], "the %s isn't affected", 68);
	strncpy_s(spelmes[5], "the %s can see you with his infravision", 68);
	strncpy_s(spelmes[6], "the %s vaporizes your missile", 68);
	strncpy_s(spelmes[7], "your missile bounces off the %s", 68);
	strncpy_s(spelmes[8], "the %s doesn't sleep", 68);
	strncpy_s(spelmes[9], "the %s resists", 68);
	strncpy_s(spelmes[10], "the %s can't hear the noise", 68);
	strncpy_s(spelmes[11], "the %s's tail cuts it free of the web", 68);
	strncpy_s(spelmes[12], "the %s burns through the web", 68);
	strncpy_s(spelmes[13], "your missiles pass right through the %s", 68);
	strncpy_s(spelmes[14], "the %s sees through your illusions", 68);
	strncpy_s(spelmes[15], "the %s loves the cold!", 68);
	strncpy_s(spelmes[16], "the %s loves the water!", 68);

	spell_tick = std::chrono::seconds(0);
	for (int i = 0; i < NUM_SPELLS; i++)
	{
		//spell_duration[i] = 5.0;
		spell_duration[i] = std::chrono::seconds(5);
		spell_damage[i] = 11;
		spell_character[i] = '~';
		
		//spell_tick_interval[i]=0.5;
		spell_tick_interval[i] = std::chrono::milliseconds(250);
		spell_color[i] = { 255,0,0 };
	}
	

}



int Spells::build_spell(char spell_char)
{
	printf("building spell\n");
	switch (char_pos)
	{
		case 0:
			casting_spell[char_pos] = spell_char;
			char_pos++;
			spell_index = -1;
			printf("spell_char1=%c\n", spell_char);
			break;
		case 1:
			casting_spell[char_pos] = spell_char;
			char_pos++;
			printf("spell_char2=%c\n", spell_char);
			break;
		case 2:
			casting_spell[char_pos] = spell_char;
			printf("spell_char3=%c\n", spell_char);
			char_pos ++;
			spell_index = 38;
			for (int i = 0; i < 38; i++)
			{
				if (strcmp(casting_spell, spellcode[i])==0)
				{
					spell_index = i;
				}
			}
			break;
	}
	if (char_pos == 3)
	{
		char_pos = 0;
		casting_spell[0] = ' ';
		casting_spell[1] = ' ';
		casting_spell[2] = ' ';
		
	}
	return spell_index;
}





