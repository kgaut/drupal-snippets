#drush_rc
À placer dans son dossier ~/.drush/

```
alias cd='cddl'
   
 # We extend the cd command to allow convenient
 # shorthand notations, such as:
 # cd @site1
 # cd %modules
 # cd %devel
 # cd @site2:%files
 # You must use 'cddl' instead of 'cd' if you are not using
 # the optional 'cd' alias from above.
 # This is the "local-only" version of the function;
 # see the cdd function, below, for an expanded implementation
 # that will ssh to the remote server when a remote site
 # specification is used.
 function cddl() {
   s="$1"
   if [ -z "$s" ]
   then
     builtin cd
   elif [ "${s:0:1}" == "@" ] || [ "${s:0:1}" == "%" ]
   then
     d="$(drush drupal-directory $1 --local 2>/dev/null)"
     if [ $? == 0 ]
     then
       echo "cd $d";
       builtin cd "$d";
     else
       echo "Cannot cd to remote site $s"
     fi
   else
     builtin cd "$s";
   fi
 }