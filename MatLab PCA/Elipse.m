x = linspace(-10, 10, 10000);
a = 1;
b = 5;
plot(x, sqrt(b*(1-(x.^2/a))) );

hold on

plot(x, -sqrt(b*(1-(x.^2/a))));

yline(0);
xline(0);