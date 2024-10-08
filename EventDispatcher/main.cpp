#include "Health.hpp"

int main()
{
   Health health;
    
    health.handle(OpenEvent{});
    health.handle(CloseEvent{});
    
    health.handle(CloseEvent{});
    health.handle(OpenEvent{});
    
    return 0;
}