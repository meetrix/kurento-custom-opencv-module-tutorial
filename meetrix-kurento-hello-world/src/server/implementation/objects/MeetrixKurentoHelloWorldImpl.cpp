/* Autogenerated with kurento-module-creator */

#include <gst/gst.h>
#include "MediaPipeline.hpp"
#include <MeetrixKurentoHelloWorldImplFactory.hpp>
#include "MeetrixKurentoHelloWorldImpl.hpp"
#include <jsonrpc/JsonSerializer.hpp>
#include <KurentoException.hpp>
#include "MediaPipelineImpl.hpp"

#define GST_CAT_DEFAULT kurento_meetrix_kurento_hello_world_impl
GST_DEBUG_CATEGORY_STATIC (GST_CAT_DEFAULT);
#define GST_DEFAULT_NAME "KurentoMeetrixKurentoHelloWorldImpl"

namespace kurento
{
namespace module
{
namespace meetrixkurentohelloworld
{

MeetrixKurentoHelloWorldImpl::MeetrixKurentoHelloWorldImpl (const boost::property_tree::ptree &config, std::shared_ptr<MediaPipeline> mediaPipeline) : OpenCVFilterImpl (config, std::dynamic_pointer_cast<MediaPipelineImpl> (mediaPipeline) )

{
}

MediaObjectImpl *
MeetrixKurentoHelloWorldImplFactory::createObject (const boost::property_tree::ptree &config, std::shared_ptr<MediaPipeline> mediaPipeline) const
{
  return new MeetrixKurentoHelloWorldImpl (config, mediaPipeline);
}

MeetrixKurentoHelloWorldImpl::StaticConstructor MeetrixKurentoHelloWorldImpl::staticConstructor;

MeetrixKurentoHelloWorldImpl::StaticConstructor::StaticConstructor()
{
  GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, GST_DEFAULT_NAME, 0,
                           GST_DEFAULT_NAME);
}

void MeetrixKurentoHelloWorldImpl::setText(const std::string &text, const int x, const int y)
{
    MeetrixKurentoHelloWorldOpenCVImpl::setText(text, x, y);
}

} /* meetrixkurentohelloworld */
} /* module */
} /* kurento */
