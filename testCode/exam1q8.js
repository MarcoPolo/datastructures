a=[1,2,3], b=[], c=[]
function moveLulz(num, from, using, to){
    if (num > 0){
        moveLulz(num-1, from, to, using);
        to.push(from.pop());
        moveLulz(num-1,using, to, from);
        moveLulz(num-1,from,using,to);
    }
}
moveLulz(3,a,b,c);


a=[1,2,3], b=[], c=[]
originalSize=a.length
for (i=0;i<originalSize-1;i++) b.push(a.pop())
c.push(a.pop())
originalSize=a.length
for (i=0;i<originalSize;i++) c.push(b.pop())
