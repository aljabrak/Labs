from playsound import playsound
import wave
import time
import os


def morse_code(string):
    """
    Returns the morse code of text. Morse code is a method used in
    telecommunication to encode text characters as standardized
    sequences of two different signal durations, called dots and
    dashes, or dits and dahs. Morse code is named after Samuel Morse,
    one of the inventors of the telegraph.
    """
    
    string = string.upper()
    character = [
        ',', '.', '?', '!', '0', '1', '2', 
        '3', '4', '5', '6', '7', '8',
        '9', 'A', 'B', 'C', 'D', 'E',
        'F', 'G', 'H', 'I', 'J', 'K',
        'L', 'M', 'N', 'O', 'P', 'Q',
        'R', 'S', 'T', 'U', 'V', 'W',
        'X', 'Y', 'Z', ' ']
    morse_code_character = [
        '--..--', '.-.-.-', '..--..', '-.-.--', '-----', 
        '.----','..---', '...--', '....-',
        '.....', '-....', '--...', '---..',
        '----.', '.-', '-...', '-.-.',
        '-..', '.', '..-.','--.',
        '....', '..', '.---', '-.-',
        '.-..', '--', '-.', '---',
        '.--.', '--.-', '.-.', '...',
        '-', '..-', '...-', '.--',
        '-..-', '-.-', '--..', '  ']

    for n in range(len(character)):
        string = string.replace(character[n], morse_code_character[n])
    code = string
    return code


def main():
    with open("morse_code.txt", 'w') as code_file:
        with open("data.txt", 'r') as file:
            text_file = file.readlines()
            for lines in text_file:
                code_file.writelines(morse_code(lines))
    
    with open('morse_code.txt', 'r') as file:
        code = file.readlines()
        for lines in code:
            for char in lines:
                if char == '.':
                    playsound('code.wav')
                    time.sleep(2)
                
                elif char == '-':
                    playsound('code.wav')
                    playsound('code.wav')
                    time.sleep(2)
            
                else:
                    time.sleep(4)


main()
