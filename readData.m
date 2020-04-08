  if ~isempty(instrfind)
       fclose(instrfind);
       delete(instrfind);
  end
    
s = serial('COM12');
fopen(s);
data = [];

FS = stoploop({'Click to End Serial Communication'}) ;

while(~FS.Stop())
val =  fscanf(s);
val = str2num(val);
data = [data, val];
end
fclose(s);