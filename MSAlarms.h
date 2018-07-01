#ifndef MSAlarms_h
#define MSAlarms_h

#include <MSPitches.h>    // note frequency definitions
	
//------------------------------------------------------------------------------------------
//  Definition of note sequences for each possible alarm melody
//------------------------------------------------------------------------------------------
// Amazing Grace                     
const Music_Note Amazing[] PROGMEM = 
//                              A     -       maz              -  ing   
                       {  {NOTE_A3, 4},{NOTE_D4, 2}, {NOTE_FS4, 4}, {NOTE_D4, 4},
                          // Grace            How           sweet          the          
                          {NOTE_FS4, 2}, {NOTE_E4, 2}, {NOTE_D4, 2}, {NOTE_B3, 2},
                          //  sound                 that           saved           a           
                          {NOTE_A3, 3}, {NOTE_REST,2},  {NOTE_A3, 4}, {NOTE_D4, 2}, {NOTE_FS4, 4}, 
                          //    wretch          like              me
                          {NOTE_D4, 4}, {NOTE_FS4, 2}, {NOTE_E4, 2},  {NOTE_A4, 1},
                        };


// Nobody Knows the Trouble I've Seen
const Music_Note Nobody[] PROGMEM = {
                      //   No    -     bod   -     y         knows        
                     {NOTE_FS4,4},{NOTE_A3,4},{NOTE_B3,4},{NOTE_D4,2},
                     //  the          trou    -     ble          I've          
                      {NOTE_E4,4},{NOTE_FS4,4},{NOTE_FS4, 2},{NOTE_FS4,4},
                     //  seen     (rest)     No     -    bod    -      y           
                     {NOTE_FS4,4},{0,2},{NOTE_FS4,4},{NOTE_A3,4},{NOTE_B3,4}, 
                     //  knows       my         sor     -    row
                     {NOTE_D4,4},{NOTE_D4,4},{NOTE_B3,4},{NOTE_A3,2}
                   };


// Little Bear
const Music_Note LittleBear[] PROGMEM = 
                        //       Lit  -     tle         Bear,                  Oh        
                        { {NOTE_FS5,4}, {NOTE_E5,4}, {NOTE_B4, 2}, {0,4}, {NOTE_A4,4},
                          // Lit      -    tle           Bear                   I
                           {NOTE_B4,4}, {NOTE_A4,4}, {NOTE_FS4, 2}, {0,4}, {NOTE_FS4,4},
                          //  see         you          when                  you're      
                          {NOTE_E4,4},{NOTE_FS4,4}, {NOTE_E4, 3},  {0,4}, {NOTE_D4,4}, 
                          //  small      and              sweet
                          {NOTE_E4,4}, {NOTE_D4,4}, {NOTE_B3, 3},  {0,3},
                          //  Lit    -   tle           Bear,                 My        
                          {NOTE_FS5,4},{NOTE_E5,4}, {NOTE_B4, 2}, {0,4}, {NOTE_A4,4},
                          // Lit      -    tle         Bear                  I
                           {NOTE_B4,4}, {NOTE_A4,4}, {NOTE_FS4, 2}, {0,4}, {NOTE_FS4,4},
                          //  Know       that          you                   are      
                          {NOTE_E4,4},{NOTE_FS4,4}, {NOTE_E4, 3},  {0,4}, {NOTE_D4,4}, 
                          //  safe         and        loved
                          {NOTE_E4,4}, {NOTE_D4,4}, {NOTE_B3, 3}, {0,4},
                          //  so        sleep         and          grow         strong
                          {NOTE_A4,4},{NOTE_B4,4}, {NOTE_A4,4},  {NOTE_B4,4}, {NOTE_FS4, 2}, {0,2},
                          //   sleep     and            grow          tall
                          {NOTE_FS4,4},{NOTE_E4,4}, {NOTE_FS4,4},  {NOTE_D4,2},{0,2},
                          //   I'll     hold          you            while           I             can               
                          {NOTE_FS4,4},{NOTE_E4,4}, {NOTE_FS4,4},  {NOTE_E4,4},  {NOTE_D4,4}, {NOTE_B3, 2}, {0,2},
                          // sort of indian melody sounding ending
                          {NOTE_A4,4},{NOTE_B4,4},{NOTE_A4,4},{NOTE_B4,4},{NOTE_A4,4},{NOTE_FS4,2},{0,2},
                          // 
                          {NOTE_E4,4},{NOTE_D4,4},{NOTE_E4,4},{NOTE_FS4,2}, 
                     };


// Mockingbird Hill                  
const Music_Note MockingbirdHill[] PROGMEM = 
                        { {NOTE_TEMPO,90},
                        //      Tra      La          La        Twee    -    dle          - lee        dee            dee
                          {NOTE_D4,8},{NOTE_G4,8},{NOTE_B4,2},{NOTE_B4,16},{NOTE_B4,16},{NOTE_B4,16},{NOTE_REST,16},{NOTE_C5,4},{NOTE_B4,4},
                        //    It         gives     me            a          thrill
                         {NOTE_A4,4},{NOTE_G4,4},{NOTE_C4,4},{NOTE_E4,4},{NOTE_D4,2},
                       //      to      wake            up          in         the      
                         {NOTE_B4,4},{NOTE_C5,2},{NOTE_A4,8},{NOTE_FS4,8},{NOTE_E4,8},
                         //  morn -     ing          to          the            mock    -   in      bird'S        trill
                          {NOTE_D4,4},{NOTE_FS4,4},{NOTE_A4,8},{NOTE_C5,8},{NOTE_B4,4},{NOTE_G4,4},{NOTE_E4,4},{NOTE_D4,2},
                       //   Tra         La          La          Twee    -   dle       -    lee           dee            dee
                          {NOTE_D4,8},{NOTE_G4,8},{NOTE_B4,2},{NOTE_B4,16},{NOTE_B4,16},{NOTE_B4,16},{NOTE_REST,16},{NOTE_C5,4},{NOTE_B4,4},
                        //     There's   peace       and        good         will
                          {NOTE_A4,4},{NOTE_G4,4},{NOTE_C4,4},{NOTE_E4,4},{NOTE_D4,2},
                        //    You're       wel   -  come         as           the       flow     -   ers
                          {NOTE_B4,4},{NOTE_C5,3},{NOTE_A4,8},{NOTE_FS4,8},{NOTE_E4,8},{NOTE_D4,4},{NOTE_FS4,4},
                        //      on      mock   -      IN        bird          hill
                          {NOTE_A4,4},{NOTE_B4,4},{NOTE_G4,4},{NOTE_G4,4},{NOTE_G4,2}, 
                        };

// Danny Boy                  
const Music_Note DannyBoy[] PROGMEM = {
                          {NOTE_TEMPO, 110},{NOTE_POWER,90},
                        //      Oh        Dan  -    ny           Boy         the           pipes       the           pipes
                         {NOTE_CS4,4},{NOTE_D4,4},{NOTE_E4,4},{NOTE_FS4,2},{NOTE_REST,8},{NOTE_E4,4},{NOTE_FS4,4},{NOTE_B4,4},{NOTE_A4,4},
                        //     are       call    -   ing         from                     glen          to             glen
                          {NOTE_FS4,4},{NOTE_E4,4},{NOTE_D4,4},{NOTE_B3,2},{NOTE_REST,4},{NOTE_D4,4},{NOTE_FS4,4},{NOTE_G4,4},{NOTE_A4,2},
                         //     and         down          the           moun        -  tain           side
                          {NOTE_B4,4},{NOTE_A4,4},{NOTE_FS4,4},{NOTE_D4,4},{NOTE_FS4,4},{NOTE_E4,2},{NOTE_REST,2},
                          //     the        sum   -     mers          gone                            
                          {NOTE_CS4,4},{NOTE_D4,4},{NOTE_E4,4},{NOTE_FS4,2},{NOTE_REST,4},
                          //     and       all        the         ro        -    ses
                          {NOTE_E4,4},{NOTE_FS4,4},{NOTE_B4,4},{NOTE_A4,4},{NOTE_FS4,4},
                         //     fall           -       ing                    it's          you           
                          {NOTE_E4,4},{NOTE_D4,4},{NOTE_B3,2},{NOTE_REST,4},{NOTE_CS4,4},{NOTE_D4,4},
                          //     it's    you             must         go        and            I      must          bide
                          {NOTE_E4,4},{NOTE_FS4,2},{NOTE_G4,4},{NOTE_FS4,4},{NOTE_E4,4},{NOTE_D4,4},{NOTE_E4,4},{NOTE_D4,2}
                        };


// Blank Space                    
const Music_Note BlankSpace[] PROGMEM = 
                        {                                           
                          {NOTE_TEMPO,70},
                          //              Nice              to  
                          {NOTE_REST,4},{NOTE_F4,16},{NOTE_F4,16},{NOTE_REST,8}, 
                          //     meet        you           
                          {NOTE_F4,16},{NOTE_F4,16}, {NOTE_REST, 8}, 
                          //   Where         you           been?       
                          {NOTE_F4,16},{NOTE_F4,16},  {NOTE_F4, 4},{NOTE_REST,16},
                          {NOTE_TEMPO,60},
                         //    I          could           show         you            
                          {NOTE_G4,16},{NOTE_A4,16},{NOTE_A4,8},{NOTE_F4,16},
                          //    in      -   cred    -      i -         ble                             things,   
                          {NOTE_F4,16},{NOTE_G4,16},{NOTE_F4,16}, {NOTE_G4,16},{NOTE_REST,16},{NOTE_F4,16},{NOTE_D4,12},{NOTE_REST,12},
                          {NOTE_TEMPO,70},
                          //     Ma     -    gic,                     mad      -      ness, 
                          {NOTE_F4,16},{NOTE_F4, 12},{NOTE_REST,12},{NOTE_F4,16},{NOTE_F4,16},{NOTE_REST,8}, 
                          //    heav   -      ven,                      sin
                          {NOTE_F4,16},{NOTE_F4,16}, {NOTE_REST,8}, {NOTE_F4,4},{NOTE_REST,8},
                          {NOTE_TEMPO,60},
                         //     Saw         you        there                                                       
                          {NOTE_G4,16},{NOTE_A4,16},{NOTE_A4,6},
                          //       and      I          thought
                          {NOTE_G4,16},{NOTE_G4,6},{NOTE_F4,6},{NOTE_REST,12},
                          //   OH              my                      God         
                          {NOTE_AS3,16},{NOTE_F4,16},{NOTE_REST,8},{NOTE_A4,4},
                          //       Look      at        that        face
                          {NOTE_C4,16},{NOTE_C4,16},{NOTE_A4,8},{NOTE_A4,3}, 
                          
                          // ALTERNATE ENDING
                          //{NOTE_C4,16},{NOTE_C4,16},{NOTE_REST,16},{NOTE_F4,4},
                          //{NOTE_C4,16},{NOTE_C4,16},{NOTE_A4,4},{NOTE_REST,16},{NOTE_A4,4}
                        };
                       
									

const Music_Note Lion[] PROGMEM = {
	{NOTE_TEMPO,90},
	//   In        the         jun   -      gle          the
	{NOTE_C5,4},{NOTE_D5,8},{NOTE_E5,4},{NOTE_D5,4},{NOTE_E5,8},
	//   might  -     y        jun     -   gle,          the
	{NOTE_F5,4},{NOTE_E5,8},{NOTE_D5,4},{NOTE_C5,4},{NOTE_D5,8},
	//  li    -      on      sleeps          to    -   night
	{NOTE_E5,4},{NOTE_D5,8},{NOTE_C5,3},{NOTE_E5,8},{NOTE_D5,1},
	//   In         the         jun   -      gle,       the
	{NOTE_G5,4},{NOTE_E5,8},{NOTE_D5,4},{NOTE_E5,4},{NOTE_G5,8},
	//   qui  -       et        jun    -   gle,          the
	{NOTE_F5,4},{NOTE_E5,8},{NOTE_D5,4},{NOTE_C5,4},{NOTE_D5,8},
	// li      -     on        sleeps      to      - night
	{NOTE_E5,4},{NOTE_D5,8},{NOTE_C5,3},{NOTE_E5,8},{NOTE_D5,1},
	//  We                                                                
	{NOTE_G5,1},{NOTE_F5,4},{NOTE_G5,4},{NOTE_F5,4},{NOTE_E5,8},
	//	wi   -    M0        -  ME    -     weh
	{NOTE_G4,4},{NOTE_G4,4},{NOTE_G4,4},{NOTE_G4,1},
	//  We
	{NOTE_G5,1},{NOTE_F5,4},{NOTE_G5,4},{NOTE_F5,4},{NOTE_E5,8},
	//	wi   -   M0       -  ME    -     weh
	{NOTE_G4,4},{NOTE_G4,4},{NOTE_G4,4},{NOTE_G4,1},
};

#endif