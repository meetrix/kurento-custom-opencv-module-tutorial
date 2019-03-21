/* Autogenerated with kurento-module-creator */

#ifndef __MEETRIX_KURENTO_HELLO_WORLD_OPENCV_IMPL_HPP__
#define __MEETRIX_KURENTO_HELLO_WORLD_OPENCV_IMPL_HPP__

#include <OpenCVProcess.hpp>
#include "MeetrixKurentoHelloWorld.hpp"
#include <EventHandler.hpp>

namespace kurento
{
namespace module
{
namespace meetrixkurentohelloworld
{

class MeetrixKurentoHelloWorldOpenCVImpl : public virtual OpenCVProcess
{

private:
  std::string textToPrint;
  int positionX;
  int positionY;

public:
  MeetrixKurentoHelloWorldOpenCVImpl ();

  virtual ~MeetrixKurentoHelloWorldOpenCVImpl () {};

  virtual void process (cv::Mat &mat);

  void setText(const std::string &text, const int x, const int y);

};

} /* meetrixkurentohelloworld */
} /* module */
} /* kurento */

#endif /*  __MEETRIX_KURENTO_HELLO_WORLD_OPENCV_IMPL_HPP__ */
