R1 = 470;
R2 = 470;
R3 = 470;
Rx = 450;
V = 3.3;

G = [];

for i = 1:8
    
    val = 3.3* ((R2.*R3 - R1.* Rx)./((R1+R3).*(R2+Rx)));
    Rx = Rx + 50;
    G = [G, val];
    
end
G