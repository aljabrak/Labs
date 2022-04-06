function [G] = transfer_function(damping_ratio, natural_frequency)
a = 2 * damping_ratio * natural_frequency;
b = natural_frequency^(2);
G = tf([b], [1, a, b]);
end