


 d1 = downsample(data1,10);
  d2 = downsample(data2,10);
   d3 = downsample(data3,10);
    d4 = downsample(data4,10);
 data = [d3; d1; d4; d2];
 
 upper = max(data(:));
 lower = min(data(:));
 diff = upper-lower;
 
 

    for i = 1:length(data)
        val = data(:,i);
    
   for j = 1:length(val)
       point = val(j);
       
       ratio = (point - lower)./diff;
       c = [ratio, 0.4, 0.4];
       scatter(j,1,500,c,'filled');
       hold on
       pause(0.05)
   end
    end

        
        
      