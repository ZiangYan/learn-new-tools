# 代码性能
* 预先分配存储空间性能可获得巨大提高。提取HOG　feature第一版我写的是：

        neg_feature = [];
        pos_feature = [];
        for patch_idx = 1 : num_patch
            if labels(patch_idx) == -1
                neg_feature = [neg_feature; HOGMap(patches(patch_idx))];
            else
                pos_feature = [pos_feature; HOGMap(patches(patch_idx))];
            end
        end
对这段代码MATLAB会给出警告：neg_feature的尺寸似乎随着迭代而变化，请提前进行内存分配能获得更高性能。第二版我把代码改为如下结构：

        neg_feature = zeros(num_patch, 640);
        pos_feature = zeros(num_patch, 640);
        num_pos = 0;
        num_neg = 0;
        for patch_idx = 1 : num_patch
            if labels(patch_idx) == -1
                num_neg = num_neg + 1
                neg_feature(num_neg, :) = HOGMap(patches(patch_idx));
            else
                num_pos = num_pos + 1;
                pos_feature(num_pos, :) = HOGMap(patches(patch_idx));
            end
        end
        neg_feature = neg_feature(1 : num_neg, :);
        pos_feature = pos_feature(1 : num_pos, :);
目测提速了10倍以上。IO的占用率从个位数提高到96%左右，CPU占用率从100%降低到15%左右，一颗赛艇！！！先前不注意这件事的原因是R-CNN的代码中存在类似问题，但作者忽略了MATLAB的警告（如果我没记错的话），我误以为这样做不会带来太多的性能提升，其实不然。