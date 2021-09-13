# AliusM(another system memory)                                                    

 * AliusM is implemented in the Linux kernel.                                      
                                                                                   
 * AliusM allows DRAM and DCPMM to act as system memory.                           
                                                                                   
   (DRAM size + DCPMM size => Total system memory size)                            
                                                                                                                                                                  
<img src="./images/alius.png" width=37%>                                           
                                                                                   
## Requirements                                                                    
                                                                                   
### Hardware                                                                       
                                                                                   
 * Second Generation Intel<sup>&reg;</sup> Xeon<sup>&reg;</sup> Sclable Processors ([Gold and Platimun tiers](https://ark.intel.com/content/www/us/en/ark/search/featurefilter.html?productType=873&2_OptaneDCPersistentMemoryVersion=True))
 * Intel<sup>&reg;</sup> Optane&trade; Persistent Memory([128GB/256GB/512GB Module](https://www.intel.com/content/www/us/en/architecture-and-technology/optane-dc-persistent-memory.html))
                                                                                   
### Software                                                                       
                                                                                   
 * Tools to building the kernel                                                    
                                                                                   
   git, make, gcc, libssl-dev, ctags, cscope, ncourse-dev                          
                                                                                   
 * On Ubuntu, you can get these tools by running:                                  
                                                                                   
   >$ sudo apt-get install libncurses5-dev gcc make git exuberant-ctags bc libssl-dev`
                                                                                   
                                                                                   
## [How to build][1]                                                               
[1]: <https://kernelnewbies.org/KernelBuild> "kernelnews"                          
                                                                                   
 * Building the kernel                                                             
```                                                                                
   $ make                                                                          
   $ sudo make modules_install install                                             
   $ sudo update-grub2                                                             
```                                                                                
## Author                                                                          
  * 李溶燮(yongseob.etri@gmail.com) (AliusM related only)
