close all;
adjust = ((5./8)./(2.^15)).*1000;

figure
plot(data1.*adjust)
title('pH Measurement')
xlabel('samples (n)')
ylabel('Voltage (mV)')

adjustData = data1.*adjust;

writematrix(adjustData','pH_data_mV.csv');