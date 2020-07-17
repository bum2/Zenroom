#!/usr/bin/env bash


####################
# common script init
if ! test -r ../utils.sh; then
	echo "run executable from its own directory: $0"; exit 1; fi
. ../utils.sh
Z="`detect_zenroom_path` `detect_zenroom_conf`"
####################

cat <<EOF | zexe array_32_256.zen > arr.json
rule output encoding url64
Given nothing
When I create the array of '32' random objects of '256' bits
and I rename the 'array' to 'bonnetjes'
Then print the 'bonnetjes'
EOF

cat <<EOF | zexe array_rename_remove.zen -a arr.json
rule input encoding url64
rule output encoding hex
Given I have a 'array' named 'bonnetjes'
When I pick the random object in 'bonnetjes'
and I rename the 'random object' to 'lucky one'
and I remove the 'lucky one' from 'bonnetjes'
# redundant check
and the 'lucky one' is not found in 'bonnetjes'
Then print the 'lucky one'
EOF

cat <<EOF | zexe array_ecp_aggregation.zen > ecp_aggregation.json
rule output encoding url64
Given nothing
When I create the array of '32' random curve points
and I rename the 'array' to 'curve points'
and I create the aggregation of 'curve points'
Then print the 'aggregation'
EOF


cat <<EOF | zexe array_hashtopoint.zen -a arr.json > ecp.json
rule input encoding url64
rule output encoding url64
Given I have a 'array' named 'bonnetjes'
When I create the hash to point 'ECP' of each object in 'bonnetjes'
# When for each x in 'bonnetjes' create the of 'ECP.hashtopoint(x)'
Then print the 'hashes'
EOF

cat <<EOF | zexe array_ecp_check.zen -a arr.json -k ecp.json > hashes.json
rule input encoding url64
rule output encoding url64
Given I have a 'array' named 'bonnetjes'
and I have a 'ecp array' named 'hashes'
# When I pick the random object in array 'hashes'
# and I remove the 'random object' from array 'hashes'
When for each x in 'hashes' y in 'bonnetjes' is true 'x == ECP.hashtopoint(y)'
Then print the 'hashes'
EOF
# 'x == ECP.hashtopoint(y)'


cat <<EOF | zexe left_array_from_hash.zen -a arr.json > left_arr.json
rule input encoding url64
rule output encoding url64
Given I have a 'array' named 'bonnetjes'
When for each x in 'bonnetjes' create the array using 'sha256(x)'
and rename the 'array' to 'left array'
Then print the 'left array'
EOF


cat <<EOF | zexe right_array_from_hash.zen -a arr.json > right_arr.json
rule input encoding url64
rule output encoding url64
Given I have a 'array' named 'bonnetjes'
When for each x in 'bonnetjes' create the array using 'sha256(x)'
and rename the 'array' to 'right array'
Then print the 'right array'
EOF

# comparison

cat <<EOF | zexe array_comparison.zen -a left_arr.json -k right_arr.json
rule input encoding url64
rule output encoding url64
Given I have a 'array' named 'left array'
and I have a 'array' named 'right array'
When I verify 'left array' is equal to 'right array'
Then print 'OK'
EOF



# 'x == ECP.hashtopoint(y)'


# When I check 'hashes' and 'bonnetjes'
# When I check 'hashes' and 'bonnetjes' such as
