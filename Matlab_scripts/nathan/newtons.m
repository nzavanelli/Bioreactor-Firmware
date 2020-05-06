close all

Tmax = 20340;
Tmin = 18160;

temp = newData1(1992:end);

tempLog = log((temp-Tmin)./(Tmax-Tmin));

plot(tempLog)
xlabel('samples');
ylabel('Log (T-A)')

t = 1:length(tempLog);

mstar = sum(tempLog.*t)./sum(t.*t);

k = (-1.861+1)./(2419-1197);

u = Tmin-300+(Tmax-Tmin).*exp(k.*t);

figure
plot(temp);hold on;plot(u)
title('Cooling Data with Fitted Model')
xlabel('samples');
ylabel('value')
legend('Recorded Data', 'Fitted Model')