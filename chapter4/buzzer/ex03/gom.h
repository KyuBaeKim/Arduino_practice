#include <pitches.h>

int durations[] = {
  // 연주 길이 정의   4: 4분 음표, 8: 8분 음표
  4, 8, 8, 4, 4,  4, 8, 8, 4, 4,  8, 8, 4, 8, 8, 4, 4, 4, 2,  
  4, 4, 4, 4,  4, 4, 2, 4, 4, 4, 4,  4, 4, 2,  
  4, 4, 4, 4,  8, 8, 8, 8, 2,  4, 4, 4, 4, 4, 4, 2
};

int notes[] = {
  // pitches.h에 정의된 음계로 정의    
  // 곰 세마리      
   NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,				// 도도도도도
   NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,     		// 미솔솔미도
   NOTE_G4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4,  // 솔솔미솔솔미     
   NOTE_C4, NOTE_C4, NOTE_C4,       							// 도도도
   
   NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,  	// 솔솔미도
   NOTE_G4, NOTE_G4, NOTE_G4,       		// 솔솔솔
   NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,    // 솔솔미도
   NOTE_G4, NOTE_G4, NOTE_G4,      			// 솔솔솔
   
   NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,     // 솔솔미도
   NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4,  // 솔솔솔라솔
   NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G4,     // 도솔도솔
   NOTE_E4, NOTE_D4, NOTE_C4
};
