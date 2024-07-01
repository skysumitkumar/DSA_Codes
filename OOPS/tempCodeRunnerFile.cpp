//here we use Animal class and cat obj
    Animal * c=new cat;
    c->Animal::color="black";
    //when we are assigning value to cat class it give error because here we make Animal class obj and Animal class not inherited cat class
    //c->cat::color="brown";
    c->printcolor();
    //when we want to call  print color of cat class than we have to use virtual keyword in Animal class than it go to print color of the cat class
    c->printcolor();