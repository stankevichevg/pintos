# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(test_multiple_operations) begin
(test_multiple_operations) Actual -52
(test_multiple_operations) Actual -53
(test_multiple_operations) end
EOF
pass;
