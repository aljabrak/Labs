function [compressed_audio] = compress(y, Frequency)
L = length(y);
z = zeros(1, L);
start_index = find(ceil(Frequency) == -5000);  % This would return a matrix.
stop_index = find(floor(Frequency) == +5000);
z(start_index(length(start_index)):stop_index(1)) = y(start_index(length(start_index)):stop_index(1));
compressed_audio = real(ifft(fftshift(z)));
end