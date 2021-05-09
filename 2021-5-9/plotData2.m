 function plotData2(X,y)
  figure;hold on;
  pos=find(y==1);
  neg=find(y==-1);  
  plot(X(pos,1),X(pos,2),'k+','Linewidth',2,'MarkerSize',4);
  plot(X(neg,1),X(neg,2),'ko','MarkerFaceColor','r','Linewidth',2,'MarkerSize',4);
 hold off;
  end