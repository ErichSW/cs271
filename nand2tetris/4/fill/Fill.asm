// watch for keyboard input (working)
(inf_loop)
@KBD
D=M
@0
M=D

// determine keypress on or off
@BLACKEN
D;JGT
@WHITEN
D;JMP

// set R3 as color to fill (black=-1, white=0)
(BLACKEN)
@3
M=-1
@FILL
0;JMP
(WHITEN)
@3
M=0
@FILL
0;JMP

// set R4 as counter
(FILL)
@8192
D=A
@4
M=D

// set R5 as screen location
@SCREEN
D=A
@5
M=D

(FILL_LOOP)
@3
D=M     // get color value
@5
A=M
M=D     // set screen to color
@5
M=M+1
@4
MD=M-1  // decrement counter
@FILL_LOOP
D;JGT   // loop til counter is 0

// loop to beginning
@inf_loop
0;JMP