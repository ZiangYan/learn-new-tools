%% compute column sum
n = 10000;
repeat_num = 10;
A = rand(n, n);
l_col = ones(n, 1);
l_row = ones(1, n);
tic;
for i = 1 : repeat_num
    sum(A, 1);
end
t_elasped = toc;
fprintf('sum method: %f\n', t_elasped);

tic;
for i = 1 : repeat_num
%     A * l_col;
    l_row * A;
end
t_elasped = toc;
fprintf('matrix product method: %f\n', t_elasped);
    