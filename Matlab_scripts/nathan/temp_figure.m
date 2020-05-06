close all;
adjust = ((5./8)./(2.^15)).*1000;

t = 1:length(data1);
fs = length(data1)./300;
 t = t./fs;

figure
plot(t, data1.*adjust)
hold on
plot(t, data2.*adjust)
plot(t, data3.*adjust)
plot(t, data4.*adjust)
title('Multiple Temperature Sensor Measurement')
xlabel('Time (s)')
ylabel('Voltage (mV)')
legend('Sensor 1', 'Sensor 2', 'Sensor 3', 'Sensor 4')

adjustData = data1.*adjust;

%writematrix(adjustData','pH_data_mV.csv');