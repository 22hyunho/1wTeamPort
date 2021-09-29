#pragma once
#include "stdafx.h"

#define EXCOLOR	RGB(214, 230, 240)
#define TILEX	32
#define TILEY	32

typedef struct tagTile {
	int r, g, b;
	float x, y, z;

	int sizeX, sizeY;
	int alpha;

	image* img;
	RECT body;

	tagTile(int R, int G, int B,
		float X, float Y, float Z,
		int SX, int SY,
		image* IMG, int blend = 0) {
		r = R;
		g = G;
		b = B;
		x = X;
		y = Y;
		z = Z;
		sizeX = SX;
		sizeY = SY;
		img = IMG;
		alpha = blend;
		body = RectMake(X, Y, sizeX, sizeY);
	}
} TILE, *PTILE;

/********** Z축 **********/
#define Z0	0
#define Z1	1
#define Z2	2
#define Z3	3
#define Z4	4

/********** RED(COLLISION) **********/
#define PASSABLE	0		//지나갈 수 있음
//#define HALFPASSABLE
#define UPDOWN		100		//이동시 Z축 변경
#define IMPASSABLE	255		//지나갈 수 없음



/********** GREEN(BOOL) **********/
#define IMMUTABLE	0		//불변
#define THROWABLE	30		//던지기 가능(들기 가능)
#define BREAKABLE	60		//파괴 가능



/********** BLUE(TILE ID) **********/
#define	NOTHING		0

//========= bush =========//
#define BUSH		1
#define BUSHOFF		2
#define WEED		3
#define RUG			4
#define GRASSTILE	5
#define BOARD		6

//========= tree =========//
#define TREEUP1			7
#define TREEUP2			8
#define TREEUP3			9
#define TREEUP4			10
#define TREEUP5			11
#define TREEDOWN1		12
#define TREEDOWN2		13
#define TREEDOWN3		14
#define TREEDOWN4		15
#define TREEDOWN5		16
#define TREEDOWN6		17
#define TREETILE1		18
#define TREETILE2		19
#define TREETILE3		20
#define TREETILE4		21
#define TREEUPINTER		22
#define TREEDOWNINTER	23

//========= stone =========//
#define STONE			24
#define STONEB			25
#define BIGSTONE		26
#define BIGSTONEB		27
#define ST5NE			28

//========= house =========//
#define HOUSE1		29
#define HOUSE2		30
#define HOUSE3		31
#define HOUSE4		32
#define HOUSE5		33
#define HOUSE6		34
#define HOUSE7		35

//========= cliff =========//
#define CLIFF1			36
#define CLIFF2			37
#define CLIFF3			38
#define CLIFF4			39
#define CLIFF5			40
#define CLIFF6			41
#define CLIFF7			42
#define CLIFF8			43
#define CLIFF9			44
#define CLIFF10			45
#define CLIFF11			46
#define CLIFF12			47
#define CLIFF13			48
#define CLIFF14			49
#define CLIFF15			50
#define CLIFF16			51
#define CLIFF17			52
#define CLIFF18			53
#define CLIFF19			54

#define CLIFFTILE1		55
#define CLIFFTILE2		56
#define CLIFFTILE3		57
#define CLIFFTILE4		58
#define CLIFFTILE5		59
#define CLIFFTILE6		60
#define CLIFFTILE7		61
#define CLIFFTILE8		62
#define CLIFFTILE9		63
#define CLIFFTILE10		64
#define CLIFFTILE11		65
#define CLIFFTILE12		66
#define CLIFFTILE13		67
#define CLIFFTILE14		68
#define CLIFFTILE15		69

#define CLIFFIN1		70
#define CLIFFIN2		71
#define CLIFFIN3		72
#define CLIFFIN4		73
#define CLIFFIN5		74
#define CLIFFIN6		75

#define CHURCH1		76
#define CHURCH2		77
#define CHURCH3		78
#define CHURCH4		79
#define CHURCH5		80
#define CHURCH6		81
#define CHURCH7		82
#define CHURCH8		83
#define CHURCH9		84

//========= road =========//
#define ROAD1		85
#define ROAD2		86
#define ROAD3		87
#define ROAD4		88
#define ROAD5		89
#define ROAD6		90
#define ROAD7		91
#define ROAD8		92
#define ROAD9		93
#define ROAD10		94
#define ROAD11		95
#define ROAD12		96
#define ROAD13		97
#define ROAD14		98

#define FENCE1		99
#define FENCE2		100
#define FENCE3		101




/*********** dungeon ***********/
//========= wall =========//
#define HANDRAIL1	102
#define HANDRAIL2	103
#define HANDRAIL3	104

#define WALLIN1		105
#define WALLIN2		106
#define WALLIN3		107
#define WALLIN4		108
#define WALLIN5		109
#define WALLIN6		110
#define WALLIN7		111
#define WALLIN8		112
#define WALLIN9		113
#define WALLIN10	114
#define WALLIN11	115
#define WALLIN12	116
#define WALLIN13	117
#define WALLIN14	118
#define WALLIN15	119
#define WALLIN16	120
#define WALLIN17	121
#define WALLIN18	122
#define WALLIN19	123
#define WALLIN20	124

#define WALLOUT1	125
#define WALLOUT2	126
#define WALLOUT3	127
#define WALLOUT4	128
#define WALLOUT5	129
#define WALLOUT6	130
#define WALLOUT7	131
#define WALLOUT8	132
#define WALLOUT9	133
#define WALLOUT10	134
#define WALLOUT11	135
#define WALLOUT12	136
#define WALLOUT13	137
#define WALLOUT14	138
#define WALLOUT15	139
#define WALLOUT16	140
#define WALLOUT17	141
#define WALLOUT18	142
#define WALLOUT19	143
#define WALLOUT20	144

#define WALL1		145
#define WALL2		146
#define WALL3		147
#define WALL4		148
#define WALL5		149
#define WALL6		150
#define WALL7		151
#define WALL8		152


//========= tile =========//
#define BORDER1			153
#define BORDER2			154
#define BORDER3			155
#define BORDER4			156
#define BORDER5			157
#define BORDER6			158
#define BORDER7			159
#define BORDER8			160

#define BOTTOMTILE		161
#define ROOFTILE		162

#define BORDER2F1		163
#define BORDER2F2		164
#define BORDER2F3		165
#define BORDER2F4		166
#define BORDER2F5		167
#define BORDER2F6		168
#define BORDER2F7		169
#define BORDER2F8		170

#define BOTTOMTILE2F	171

//========= path =========//
//#define DOORUP1			172
//#define DOORUP2			173

#define DOORRIGHT1		172
#define DOORRIGHT2		173
#define DOORRIGHT3		174
#define DOORRIGHT4		175

//#define DOORDOWN1		176
//#define DOORDOWN2		177

#define DOORLEFT1		176
#define DOORLEFT2		177
#define DOORLEFT3		178
#define DOORLEFT4		179

#define DOORDOWN2F1		180
#define DOORDOWN2F2		181
#define DOORDOWN2F3		182
#define DOORDOWN2F4		183

#define LADDER1			184
#define LADDER2			185
#define LADDER3			186
//#define LADDER4			183

//#define UPSTAIR1		184
//#define UPSTAIR2		185
//#define UPSTAIR3		186
//#define UPSTAIR4		187
#define DOWNSTAIR1		188
#define DOWNSTAIR2		189
#define DOWNSTAIR3		190
#define DOWNSTAIR4		191


//========= object =========//
#define BOX			192
#define BOXOPEN		193

#define CANDLE1		194
#define CANDLE2		195
#define CANDLE3		196
#define CANDLE4		197

#define JAR			198
#define JARBOTTOM	199

#define PILLAR1		200
#define PILLAR2		201
#define PILLAR3		202

#define STATUE		203



//========= wall2 =========//
#define WALL2OUT1		204
#define WALL2OUT2		205
#define WALL2OUT3		206
#define WALL2OUT4		207
#define WALL2OUT5		208
#define WALL2OUT6		209
#define WALL2OUT7		210
#define WALL2OUT8		211

#define WALL2IN1		212
#define WALL2IN2		213
#define WALL2IN3		214
#define WALL2IN4		215
#define WALL2IN5		216
#define WALL2IN6		217
#define WALL2IN7		218
#define WALL2IN8		219
#define WALL2IN9		220
#define WALL2IN10		221
#define WALL2IN11		222
#define WALL2IN12		223



#define HOLE		253
#define BOTTOM		254
#define COLLISION	255