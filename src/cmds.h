//
//  cmds.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_cmds_h
#define cyril2_cmds_h

#define CMD_OP_COUNT 50

#define CMD_LOAD 0
#define CMD_SAVE 1
#define CMD_SAVE_NOPOP 37
#define CMD_PUSH 3
#define CMD_JUMP 4
#define CMD_IF 5
#define CMD_JUMPNIF 33
#define CMD_JUMPNIF_NOPOP 38
#define CMD_DEC_F 34
#define CMD_INC_F 39

#define OP_DEBUG 41
#define OP_MOVE 6
#define OP_ROTATE 7
#define OP_SCALE 46
#define OP_PUSH_MATRIX 47
#define OP_POP_MATRIX 48

#define OP_BACKGROUND 44
#define OP_COLOR 45

#define OP_BOX 8
#define OP_LINE 9
#define OP_BALL 10
#define OP_SPHERE 49
#define OP_PEG 11
#define OP_CONE 12
#define OP_RECT 13
#define OP_PARTICLE 14
#define OP_GRID 43

#define OP_PLUS 15
#define OP_MINUS 16
#define OP_DIV 17
#define OP_MULT 18
#define OP_MOD 19

#define OP_EQ 20
#define OP_NOTEQ 21
#define OP_LESS 22
#define OP_LESS_1POP 40
#define OP_LESSEQ 23
#define OP_GR 24
#define OP_GREQ 25
#define OP_GREQ_1POP 42
#define OP_NOT 26
#define OP_AND 35
#define OP_OR 36

#define FUN_WAVE 27
#define FUN_SIN 28
#define FUN_COS 29
#define FUN_TAN 30
#define FUN_NOISE 31
#define FUN_RAND 32

#define REG_COUNT 68

#define REG_TIME 0
#define REG_FRAME 1
#define REG_PI 13
#define REG_TWO_PI 14
#define REG_X_MAX 17
#define REG_Y_MAX 18
#define REG_X_MID 19
#define REG_Y_MID 20
#define REG_SECS 28
#define REG_FAST 29
#define REG_SLOW 30

#define REG_X_SCALE 21
#define REG_Y_SCALE 22
#define REG_Z_SCALE 23

#define REG_PARTICLE_HEALTH 15
#define REG_PARTICLE_DECAY 16

#define REG_MIND_SIGNAL 2
#define REG_MIND_ATTENTION 3
#define REG_MIND_MEDITATION 4
#define REG_MIND_DELTA 5
#define REG_MIND_THETA 6
#define REG_MIND_LOWALPHA 7
#define REG_MIND_HIGHALPHA 8
#define REG_MIND_LOWBETA 9
#define REG_MIND_HIGHBETA 10
#define REG_MIND_LOWGAMMA 11
#define REG_MIND_MIDGAMMA 12

#define REG_BEAT_KICK 24
#define REG_BEAT_SNARE 25
#define REG_BEAT_HIHAT 26
#define REG_BEAT_MAGNITUDE 27
#define REG_BEAT_FFT_START 35
#define REG_BEAT_FFT_MAX 67

#define REG_COLOR_WHITE 31
#define REG_COLOR_GRAY 32
#define REG_COLOR_BLACK 33
#define REG_COLOR_RED 34


#endif
