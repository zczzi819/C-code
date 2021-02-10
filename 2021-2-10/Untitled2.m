
clear;clc;close all;
X = imread('standard_lena.bmp');

[c,s]=wavedec2(X,2,'haar');


[H1,V1,D1] = detcoef2('all',c,s,1);
[H2,V2,D2] = detcoef2('all',c,s,2);
A2 = appcoef2(c,s,'haar',2);

X_A2 = wrcoef2('a',c,s,'sym5',1); 
X_H1 = wrcoef2('h',c,s,'sym5',1); 
X_V1 = wrcoef2('v',c,s,'sym5',1); 
X_D1 = wrcoef2('d',c,s,'sym5',1); 
X_H2 = wrcoef2('h',c,s,'sym5',2); 
X_V2 = wrcoef2('v',c,s,'sym5',2); 
X_D2 = wrcoef2('d',c,s,'sym5',2); 


figure(1);imshow(X_A2,[]);saveas(1,'/lena_A2.bmp');
figure(2);imshow(X_H1,[]);saveas(2,'/lena_H1.bmp');
figure(3);imshow(X_V1,[]);saveas(3,'/lena_V1.bmp');
figure(4);imshow(X_D1,[]);saveas(4,'/lena_D1.bmp');
figure(5);imshow(X_H2,[]);saveas(5,'/lena_H2.bmp');
figure(6);imshow(X_V2,[]);saveas(6,'/lena_V2.bmp');
figure(7);imshow(X_D2,[]);saveas(7,'/lena_D2.bmp');

c_RemainPortion = 0.05;
c_end = s(1,1)^2+round((length(c)-  s(1,1)^2)*c_RemainPortion);
c_Recon1 =zeros(1,length(c));
c_Recon1(1:c_end) = c(1:c_end);
X_Recon1 = uint8(waverec2(c_Recon1,s,'haar'));
figure(8);imshow(X_Recon1,[]);title('5%');saveas(8,'/lena_Recon1.bmp');

c_RemainPortion = 0.1;
c_end = s(1,1)^2+round((length(c)-  s(1,1)^2)*c_RemainPortion);
c_Recon2 =zeros(1,length(c));
c_Recon2(1:c_end) = c(1:c_end);
X_Recon2 = uint8(waverec2(c_Recon2,s,'haar'));
figure(9);imshow(X_Recon2,[]);title('10%');saveas(9,'/lena_Recon2.bmp');

c_RemainPortion = 0.2;
c_end = s(1,1)^2+round((length(c)-  s(1,1)^2)*c_RemainPortion);
c_Recon3 =zeros(1,length(c));
c_Recon3(1:c_end) = c(1:c_end);
figure(10);X_Recon3 = uint8(waverec2(c_Recon3,s,'haar'));
figure(9);imshow(X_Recon3,[]);title('20%');saveas(9,'/lena_Recon3.bmp');


entropy(X);
entropy(X_Recon1)
MSE1 = mean(mean(X-X_Recon1).^2);
PSNR1 = 20*log10(double(255/MSE1))
entropy(X_Recon2)
MSE2 = mean(mean(X-X_Recon2).^2);
PSNR2 = 20*log10(double(255/MSE2))
entropy(X_Recon3)
MSE3 = mean(mean(X-X_Recon3).^2);
PSNR3 = 20*log10(double(255/MSE3))


