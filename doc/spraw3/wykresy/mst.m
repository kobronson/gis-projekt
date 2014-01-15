%500 wezlow
% k=[14 24 41 53 70]
% p=[2 7 14 20 30]
% s='MST: |V|=500'

%1000 wezlow
% k=[49 132 155 159 220]
% p=[17 49 62 75 120]
% s='MST: |V|=1000'

%2000 wezlow
% k=[94 239 380 540 730]
% p=[39 116 183 259 329]
% s='MST: |V|=2000'

%3000 wezlow
k=[161 521 895 2615]
p=[82 256 439 611]
s='MST: |V|=3000'

%memory
% k=[2376 7066 11747 16434 21122]
% p=[9436 28190 46901 65662 84410]
% s='Zuzycie pamieci dla |V|=2000'






y=[0.1 0.3 0.5 0.7]
scrsz = get(0,'ScreenSize');
figure('OuterPosition',[1 scrsz(4)/2 945 448])
plot(y,p,'b+')
hold
axis([0 0.8 0 k(length(k))+100])

plot(y,k,'r*')

xlabel('p')
ylabel('[ms]')
title(s);
legend('Prim','Kruskal','Location','NorthWest')





