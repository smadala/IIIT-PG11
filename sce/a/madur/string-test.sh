#string checks

s1="hello!!"
s2="h r u"
s3=""

[ "$s1" = "$s2" ]

echo $?

[ "$s1" != "$s2" ]

echo $?

[ -n "$s1" ]

echo $?

[ -z "$s3" ]

echo $?

