#include <thread>
#include "jack_module.h"
#include "math.h"
#include <iostream>
#include <stdio.h>
#include "threedelay.h"

#include "RandomOSC.h"


int main(int argc, char **argv) {
	
	JackModule jack;
	
	jack.init(argv[0]);
	float samplerate = jack.getSamplerate();
	
	RandomOSC OSC1;
	RandomOSC OSC2;
	RandomOSC OSC3;

	Threedelay threedelay(44100);
	threedelay.setDelayTimes(200, 300, 5000);

	int outdex_1=1;
	int outdex_2=1;
	int outdex_3=1;
	
	jack.onProcess = [&threedelay, &OSC1, &OSC2, &OSC3, &outdex_1, &outdex_2, &outdex_3](jack_default_audio_sample_t *inBuf,
		jack_default_audio_sample_t *outBuf, jack_nframes_t nframes){
			
			

		for(unsigned int i = 0; i < nframes; i++) {
			threedelay.takeInput(inBuf[i]);	
			threedelay.tick();
			
			outdex_1++;
			outdex_2++;
			outdex_3++;

			outBuf[i] = threedelay.pushOutput();
			threedelay.anal(threedelay.pushOutput());

			threedelay.setDelayTimes(round(((OSC1.interpOsc(4000) * 200) + 20)), 
									round(((OSC2.interpOsc(1000) * 2000) + 200)),
									round(((OSC3.interpOsc(2000) * 5000) + 200)));
		//	std::cout << OSC1.outputRandom() << std::endl;

			if(outdex_1 >= 4000){
			OSC1.rOsc();
		//	 OSC1.interpOsc(4000);
			outdex_1 = 1;
			}

			if(outdex_2 >= 1000){
			OSC2.rOsc();
		//	OSC2.interpOsc(1000);
			outdex_2 = 1;
			}

			if(outdex_3 >= 2000){
			OSC3.rOsc();
		//	OSC3.interpOsc(2000);
			outdex_3 = 1;
			}
				
		}
		return 0;
	};
	
	jack.autoConnect();
	
	std::cout << "\n\nPress 'q' when you want to quit the program.\n";
	bool running = true;
	while (running)
	{
		switch (std::cin.get())
		{
			case 'q':
				running = false;
				jack.end();
				break;
		}
	}
	
	return 0;
}
