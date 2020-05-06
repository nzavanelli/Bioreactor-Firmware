 clear
if ~isempty(instrfind)
       fclose(instrfind);
       delete(instrfind);
  end
    
s = serial('COM4'); %Depends on the com port the arduino is on
fopen(s);
data1 = [];
data2 = [];
data3 = [];
data4 = [];

FS = stoploop({'Click to End Serial Communication'}) ;

while(~FS.Stop())
    
val1 =  fscanf(s);
val1 = str2num(val1);

data1 = [data1, val1];


 val2 =  fscanf(s);
 val2 = str2num(val2);
 data2 = [data2, val2];
 
 val3 =  fscanf(s);
 val3 = str2num(val3);
 data3 = [data3, val3];

  val4 =  fscanf(s);
 val4 = str2num(val4);
 data4 = [data4, val4];

end
fclose(s);

figure
plot(data1); hold on; plot(data2); plot(data3); plot(data4)
title('pH Measurement')
xlabel('samples (n)')
ylabel('Voltage (digital reference)')
legend('Sensor 1', 'Sensor 2', 'Sensor 3', 'Sensor 4')



