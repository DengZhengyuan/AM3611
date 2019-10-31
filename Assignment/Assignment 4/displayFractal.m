% To get best results, set the dimensions of your fractal matrix to 600 by
% 600
A = importdata('julia.dat'); % change filename 'julia.dat' to the filename that you have outputted your data

% Create your color map, Google "matlab colormap" and click on first link for other colormap
% schemes
cmap = jet(81); % change this number "81" to the max number of iterations in your program + 1

imwrite(A, cmap, 'julia.png'); % feel free to change 'julia.png' to the output filename of your choosing