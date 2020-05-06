function [ all_d1, all_d2]= mcp_bt_trial(bt, val)
    fprintf(bt,val);
    data_set =1;  
    all_d1 = [];
    all_d2 = [];
    for i = 1:val
        d1= [];                                                                
        d2 = [];
        d1 = gather(d1, bt);
        all_d1 = [all_d1, d1];
        d2 = gather(d2,bt);
        all_d2 = [all_d2, d2];
    end
    fprintf(bt,'n');
    end
    function in = gather(in, device)
        while(length(in) ~=8 )
            in = [in; fscanf(device, '%f')];
        end
    end