/*
In case given below, after switch, Object t doesn't go out 
of scope.
*/
/*
Thing t = someFunction(stuff);
switch(t.getStatus())
{
case value1:
// ...action...
break;
default:
// ...action...
}
*/

/*
In case given below, the after switch, Object t goes out 
of scope. This is useful if t is used only for switch and 
developer wants t to release its resources after switch.
*/
/*
switch(Thing t = someFunction(stuff); t.getStatus())
{
case value1:
// ...action...
break;
default:
// ...action...
}
*/