# Welcome to Geekble_Oscillator<br>
# Geekble_Oscilltor에 오신것을 환영합니다.<br>
<br>
Geekble_Oscillator generates pulse from 8MHz to 31.25KHz with fixed 50% duty ratio.<br>
Geekble_Oscillator는 50% 고정 Duty비를 갖는 8MHz 에서 31.25KHz까지의 펄스를 발생시킵니다.<br>
<br>
This Library occupies Timer Counter 2, which will affect the functions or library depend on Timer Counter 2.<br>
이 라이브러는 Timer Counter 2를 사용합니다. 따라서 Timer Counter 2를 사용하는 다른 기능 또는 라이브러리에 영향을 미칩니다.<br>
<br>
<br>


***
## Instruction<br>
<br>

    // Construct Class, Initialize function.                                        // Class를 생성하고 초기화합니다.
    Geekble_Oscillator();

    // Set output frequency, from 8MHz to 31.25KHz                                  // 8MHz부터 31.25KHz 까지의 출력주파수를 설정합니다.
    // Output Frequency = 8MHz / Divide_Variable                                    // 출력주파수 = 8MHz / Divide_Variable
    // ex: Geekble_Oscillator OSC (1); -> 8MHz                                      // 예시: Geekble_Oscillator OSC (1); -> 8MHz
    // ex: Geekble_Oscillator OSC (10); -> 800KHz                                   // 예시: Geekble_Oscillator OSC (10); -> 800KHz
    void Divide_8MHz_by(uint16_t Divide_Variable);

    // Set Oscilltor On or Off                                                      // Oscillator를 켜거나 끌지를 선택합니다.
    // If On_Off = 1, Output Frequency will generated on Digital pin 11             // On_Off = 1인 경우, Digital pin 11에서 출력주파수가 발생합니다.
    // If On_Off = 0, Timer Counter Stop, Digital pin 11 return to normal operation // On_Off = 0인 경우, 타이머카운터가 정지합니다. Digital pin 11은 기본 pin으로 동작합니다.
    void Run(uint8_t On_Off);


***
## Example<br>
<br>
    #include <Geekble_Oscillator.h>
    
    // Output Frequency = 8MHz / Divide_Variable                            // 출력주파수 = 8MHz / Divide_Variable
    // ex: Geekble_Oscillator OSC (1); -> 8MHz                              // 예시: Geekble_Oscillator OSC (1); -> 8MHz
    // ex: Geekble_Oscillator OSC (10); -> 800KHz                           // 예시: Geekble_Oscillator OSC (10); -> 800KHz
    // Divide_Variable from 1 (8MHz) to 256 (31.25KHz)                      // Divide_Variable의 범위는 1 (8MHz)에서 256(31.25KHz)까지입니다.
    // OC2A pin is used for Oscillator Output, which is Digital pin 11      // 출력포트로 OC2A핀을 사용합니다. 이는 Digital pin 11 핀입니다.
    
    // In this example, we are going to sweep output frequency              // 이 예제에서, 우리는 출력주파수를 변화(Sweep)시킬것입니다.
    // Every 1 Sec, Devide_Variable will increase +1                        // 매 1초마다, Divide_Variable이 1씩 증가할것입니다.
    // It will Sweep Frequency from 8MHz to 31.25KHz                        // 이는 출력주파수를 8MHz부터 31.25KHz까지 변화(Sweep)하게 합니다.
    // Let's get started.                                                   // 시작해봅시다.
    
    // Construct Freq_Sweep                                                 // Freq_Sweep을 생성합니다.
    Geekble_Oscillator Freq_Sweep;
    
    void setup()
    {
        // Initialize Freq_Sweep                                            // Freq_Sweep을 초기화합니다.
        Freq_Sweep = Geekble_Oscillator();
    
        // Set output frequency, Output Frequency = 8MHz / 1 = 8MHz         // 출력주파수를 설정합니다. 출력주파수 = 8MHz / 1 = 8MHz
        Freq_Sweep.Divide_8MHz_by(1);
    
        // Run Oscilltor, Output Frequency now generated on Digital pin 11  // Oscillator를 동작합니다. 출력주파수가 이제 Digital pin 11에서 발생합니다.
        Freq_Sweep.Run(1);
    }
    
    void loop()
    {
        // Sweep Divide_Variable from 1 to 256 every seconds                // Divide_Variable 값을 1초간격으로 1부터 256까지 변화시킵니다.
        for (int Divide_Variable = 1; Divide_Variable <= 256; Divide_Variable++)
        {
            Freq_Sweep.Divide_8MHz_by(Divide_Variable);
            _delay_ms(1000);
        }
    
        // Terminate Oscillator                                             // 출력을 중단합니다.
        Freq_Sweep.Run(0);

    }