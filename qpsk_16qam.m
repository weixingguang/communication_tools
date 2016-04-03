qam16 = [1+1j 1+3j 3+1j 3+3j -1+1j -1+3j -3+1j -3+3j -1-1j -1-3j -3-1j -3-3j 1-1j 1-3j 3-1j 3-3j];
qpsk  =[1+1j 1-1j -1-1j -1+1j];
qam16 = qam16./sqrt(10);
qpsk  = qpsk ./sqrt(2);

power_rate_near = 1/10;
power_rate_far = 1 - power_rate_near;

for i = 1:4
	for j = 1:16
		qam64((i-1)*16 + j) = qam16(j)*sqrt(power_rate_near) + qpsk(i)*sqrt(power_rate_far);
	end
end

plot(qam64,'.');
hold on;
plot(qpsk,'r*');

