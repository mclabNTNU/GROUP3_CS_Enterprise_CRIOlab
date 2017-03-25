% PLOT THE POSITION IN THE TANK

close all
limit = 0.8;
% Position in the tank
title('Position in the XY-plane ')

plot(x_in,y_in,x_d,y_d,x_hat,y_hat); 
axis([-20-2,20+2,(-6.45-1*0.5), (6.4+1*0.5)]);
xlabel('x-dir');
ylabel('y-dir');
legend('Measured pos','Desired pos','Estimated');

% Lines marking the end of the basin
rectangle('Position',[-20,-3.45,40,6.45],'LineStyle','-');
hold on;

% Lines marking the end of the "safe sone"
rectangle('Position',([-20,-3.45,40,6.45]*limit),'LineStyle','--');
hold on; 
