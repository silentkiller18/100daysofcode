select a.id from weather a,weather b
where DATEDIFF(a.recordDate ,b.recordDate)=1
and a.temperature>b.temperature;