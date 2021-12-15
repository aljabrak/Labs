# DTMF Encoder Decoder
When we touch a touch-tone pad of Telephone it generates signals in the form of dual tone multiple frequency (DTMF) in order to dial a telephone.
When any number is dialed and the key is pressed, s sinusoidal waves of the corresponding row and column frequencies are generated and summed together. 
The frequencies for each number are given in the table. For instance, if a 3 key is pressed, signal is generated containing the sum of the two frequencies/tones, 
697 Hz and 1477 Hz. The frequencies for each digit are chosen by design engineers to avoid harmonics. 
The sum and difference between any two frequencies does not come equal to any of the given frequency and no frequency is an integer multiple of another. 
This allows to detect the tones in the dialed signal easily even in the presence of non-linear line distortions.


| Frequency (Hz) | 1290 | 1336 | 1447 |
| ---------------|------|------|------|
|      697       |   1  |   2  |   3  |
|      770       |   4  |   5  |   6  |
|      852       |   7  |   8  |   9  |
|      941       |   *  |   0  |   #  |
