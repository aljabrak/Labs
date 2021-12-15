function [xx,tt] = syn_sin(fk, Xk, fs, dur, t_start)
xx = 0;
en = 0;
tt = 0;
t_start = 0;
en = input('Enter specific starting value of time-scale(1/0): ');
if en == 1
    t_start = input('Enter the new value: ');
end
if en==0
    t_start = 0;
else
    disp('Wrong-Value... Setting Default...')
    t_start = 0;
end

tt = t_start:(dur+t_start)/fs:(dur+t_start);

if length(fk) == length(Xk)
    for k = 1:length(Xk)
       x1 = Xk(k)*exp(1j*2*pi*fk(k)*tt);
       xx = xx+x1;
    end
end
plot(tt,xx);
end




