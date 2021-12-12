from numpy import *
from matplotlib.pyplot import *
from scipy import signal
from scipy.fft import fft
import wave
import os


PATH = 'Audio'
sound_file = 'piano_c.wav'

audio = wave.open(os.path.join(PATH, sound_file), 'r')
[W, H] = signal.freqz(audio)
plot(W, abs(H))
plot(W)
