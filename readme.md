# Unreal Engine: Struct Replication Example

----
## controls
W,A,S,D for movement

Left Mouse Clicks on the buttons

----
## notes

* ** Open TestLevel!**
* Each player can only change its own values.
* There is a replication log, showing the history
* To the left of the replication log, the current values are shown. Some are updated via the OnRep function, some via the Bindings.
* Technically the Listen Server could also change the values of the clients, but its currently prohibited by the *AllowedToChangeStruct*-Macro in the *ReplicationLog*-Widget.

----
## proof of concept
![this should be an example pic](https://github.com/smaradey/UnrealStructReplication/blob/master/example.PNG "Its working:")



